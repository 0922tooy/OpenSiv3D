﻿//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2018 Ryo Suzuki
//	Copyright (c) 2016-2018 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# include <Siv3D/Dialog.hpp>
# include <Siv3D/Image.hpp>
# include <Siv3D/Texture.hpp>
# include <Siv3D/Wave.hpp>
# include <Siv3D/Audio.hpp>

namespace s3d
{
	namespace detail
	{
		const Array<FileFilter> OpenImageFilters =
		{
			FileFilter::AllImageFiles(),
			FileFilter::PNG(),
			FileFilter::JPEG(),
			FileFilter::BMP(),
			FileFilter::GIF(),
			FileFilter::TGA(),
			FileFilter::PPM(),
		};

		const Array<FileFilter> OpenAudioFilters =
		{
			FileFilter::AllAudioFiles(),
			FileFilter::WAVE(),
			FileFilter::MP3(),
			FileFilter::AAC()
		};

		const Array<FileFilter> SaveImageFilters =
		{
			FileFilter::PNG(),
			FileFilter::JPEG(),
			FileFilter::BMP(),
			FileFilter::GIF(),
			FileFilter::TGA(),
			FileFilter::PPM(),
		};
	}

	namespace Dialog
	{
		Image OpenImage(const FilePath& defaultPath, const String& title)
		{
			if (const auto path = OpenFile(detail::OpenImageFilters, defaultPath, title))
			{
				return Image(path.value());
			}
			else
			{
				return Image();
			}
		}

		Texture OpenTexture(const FilePath& defaultPath, const String& title)
		{
			if (const auto path = OpenFile(detail::OpenImageFilters, defaultPath, title))
			{
				return Texture(path.value());
			}
			else
			{
				return Texture();
			}
		}

		Texture OpenTexture(const TextureDesc desc, const FilePath& defaultPath, const String& title)
		{
			if (const auto path = OpenFile(detail::OpenImageFilters, defaultPath, title))
			{
				return Texture(path.value(), desc);
			}
			else
			{
				return Texture();
			}
		}

		Wave OpenWave(const FilePath& defaultPath, const String& title)
		{
			if (const auto path = OpenFile(detail::OpenAudioFilters, defaultPath, title))
			{
				return Wave(path.value());
			}
			else
			{
				return Wave();
			}
		}

		Audio OpenAudio(const FilePath& defaultPath, const String& title)
		{
			if (const auto path = OpenFile(detail::OpenAudioFilters, defaultPath, title))
			{
				return Audio(path.value());
			}
			else
			{
				return Audio();
			}
		}

		Audio OpenAudio(const Arg::loop_<bool> loop, const FilePath& defaultPath, const String& title)
		{
			if (const auto path = OpenFile(detail::OpenAudioFilters, defaultPath, title))
			{
				return Audio(path.value(), loop);
			}
			else
			{
				return Audio();
			}
		}

		Optional<FilePath> SaveImage(const FilePath& defaultPath, const String& title)
		{
			return SaveFile(detail::SaveImageFilters, defaultPath, title);
		}
	}
}
