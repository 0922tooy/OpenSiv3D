//-----------------------------------------------
//
//	This file is part of the Siv3D Engine.
//
//	Copyright (c) 2008-2018 Ryo Suzuki
//	Copyright (c) 2016-2018 OpenSiv3D Project
//
//	Licensed under the MIT License.
//
//-----------------------------------------------

# pragma once
# include <cassert>

namespace s3d
{
	class ISiv3DLicenseManager;
	class ISiv3DLogger;
	class ISiv3DSystem;
	class ISiv3DCPU;
	class ISiv3DConsole;
	class ISiv3DImageFormat;
	class ISiv3DObjectDetection;
	class ISiv3DWindow;
	class ISiv3DProfiler;
	class ISiv3DTextToSpeech;
	class ISiv3DClipboard;
	class ISiv3DDragDrop;
	class ISiv3DCursor;
	class ISiv3DKeyboard;
	class ISiv3DMouse;
	class ISiv3DGamepad;
	class ISiv3DXInput;
	class ISiv3DTextInput;
	class ISiv3DCodec;
	class ISiv3DAudioFormat;
	class ISiv3DSoundFont;
	class ISiv3DAudio;
	class ISiv3DFFT;
	class ISiv3DNetwork;
	class ISiv3DGraphics;
	class ISiv3DTexture;
	class ISiv3DShader;
	class ISiv3DRenderer2D;
	class ISiv3DScreenCapture;
	class ISiv3DFont;
	class ISiv3DEffect;
	class ISiv3DWebcam;
	class ISiv3DPrint;
	class ISiv3DScript;
	class ISiv3DAsset;

	template <class Interface>
	class Siv3DComponent
	{
	private:

		Interface * pInterface = nullptr;

	public:

		Siv3DComponent()
			: pInterface(Interface::Create()) {}

		~Siv3DComponent()
		{
			assert(pInterface == nullptr);
		}

		Interface* get()
		{
			return pInterface;
		}

		void release()
		{
			delete pInterface;

			pInterface = nullptr;
		}
	};

	class Siv3DEngine
	{
	private:

		inline static Siv3DEngine* pEngine = nullptr;

		Siv3DComponent<ISiv3DLicenseManager> m_licenseManager;

		Siv3DComponent<ISiv3DLogger> m_logger;

		Siv3DComponent<ISiv3DSystem> m_system;

		Siv3DComponent<ISiv3DCPU> m_cpu;

		Siv3DComponent<ISiv3DConsole> m_console;

		Siv3DComponent<ISiv3DImageFormat> m_imageFormat;

		Siv3DComponent<ISiv3DObjectDetection> m_objectDetection;

		Siv3DComponent<ISiv3DWindow> m_window;

		Siv3DComponent<ISiv3DProfiler> m_profiler;

		Siv3DComponent<ISiv3DTextToSpeech> m_textToSpeech;

		Siv3DComponent<ISiv3DClipboard> m_clipboard;

		Siv3DComponent<ISiv3DDragDrop> m_dragdrop;

		Siv3DComponent<ISiv3DCursor> m_cursor;

		Siv3DComponent<ISiv3DKeyboard> m_keyboard;

		Siv3DComponent<ISiv3DMouse> m_mouse;

		Siv3DComponent<ISiv3DGamepad> m_gamepad;

		Siv3DComponent<ISiv3DXInput> m_xInput;

		Siv3DComponent<ISiv3DTextInput> m_textInput;

		Siv3DComponent<ISiv3DCodec> m_codec;

		Siv3DComponent<ISiv3DAudioFormat> m_audioFormat;

		Siv3DComponent<ISiv3DSoundFont> m_soundFont;

		Siv3DComponent<ISiv3DAudio> m_audio;

		Siv3DComponent<ISiv3DFFT> m_fft;

		Siv3DComponent<ISiv3DNetwork> m_network;

		Siv3DComponent<ISiv3DGraphics> m_graphics;

		Siv3DComponent<ISiv3DTexture> m_texture;

		Siv3DComponent<ISiv3DShader> m_shader;

		Siv3DComponent<ISiv3DRenderer2D> m_renderer2D;

		Siv3DComponent<ISiv3DScreenCapture> m_screenCapture;

		Siv3DComponent<ISiv3DFont> m_font;

		Siv3DComponent<ISiv3DPrint> m_print;

		Siv3DComponent<ISiv3DEffect> m_effect;

		Siv3DComponent<ISiv3DWebcam> m_webcam;

		Siv3DComponent<ISiv3DScript> m_script;

		Siv3DComponent<ISiv3DAsset> m_asset;
		
	public:

		Siv3DEngine();

		~Siv3DEngine();

		static bool isActive()
		{
			return pEngine != nullptr;
		}

		static ISiv3DLicenseManager* GetLicenseManager()
		{
			return pEngine->m_licenseManager.get();
		}

		static ISiv3DLogger* GetLogger()
		{
			return pEngine->m_logger.get();
		}

		static ISiv3DSystem* GetSystem()
		{
			return pEngine->m_system.get();
		}

		static ISiv3DCPU* GetCPU()
		{
			return pEngine->m_cpu.get();
		}

		static ISiv3DConsole* GetConsole()
		{
			return pEngine->m_console.get();
		}

		static ISiv3DImageFormat* GetImageFormat()
		{
			return pEngine->m_imageFormat.get();
		}

		static ISiv3DObjectDetection* GetObjectDetection()
		{
			return pEngine->m_objectDetection.get();
		}

		static ISiv3DWindow* GetWindow()
		{
			return pEngine->m_window.get();
		}

		static ISiv3DProfiler* GetProfiler()
		{
			return pEngine->m_profiler.get();
		}

		static ISiv3DTextToSpeech* GetTextToSpeech()
		{
			return pEngine->m_textToSpeech.get();
		}

		static ISiv3DClipboard* GetClipboard()
		{
			return pEngine->m_clipboard.get();
		}
		
		static ISiv3DDragDrop* GetDragDrop()
		{
			return pEngine->m_dragdrop.get();
		}

		static ISiv3DCursor* GetCursor()
		{
			return pEngine->m_cursor.get();
		}

		static ISiv3DKeyboard* GetKeyboard()
		{
			return pEngine->m_keyboard.get();
		}

		static ISiv3DMouse* GetMouse()
		{
			return pEngine->m_mouse.get();
		}

		static ISiv3DGamepad* GetGamepad()
		{
			return pEngine->m_gamepad.get();
		}

		static ISiv3DWebcam* GetWebcam()
		{
			return pEngine->m_webcam.get();
		}

		static ISiv3DXInput* GetXInput()
		{
			return pEngine->m_xInput.get();
		}

		static ISiv3DTextInput* GetTextInput()
		{
			return pEngine->m_textInput.get();
		}

		static ISiv3DCodec* GetCodec()
		{
			return pEngine->m_codec.get();
		}

		static ISiv3DAudioFormat* GetAudioFormat()
		{
			return pEngine->m_audioFormat.get();
		}

		static ISiv3DSoundFont* GetSoundFont()
		{
			return pEngine->m_soundFont.get();
		}

		static ISiv3DAudio* GetAudio()
		{
			return pEngine->m_audio.get();
		}

		static ISiv3DFFT* GetFFT()
		{
			return pEngine->m_fft.get();
		}

		static ISiv3DNetwork* GetNetwork()
		{
			return pEngine->m_network.get();
		}

		static ISiv3DGraphics* GetGraphics()
		{
			return pEngine->m_graphics.get();
		}

		static ISiv3DTexture* GetTexture()
		{
			return pEngine->m_texture.get();
		}

		static ISiv3DShader* GetShader()
		{
			return pEngine->m_shader.get();
		}

		static ISiv3DRenderer2D* GetRenderer2D()
		{
			return pEngine->m_renderer2D.get();
		}

		static ISiv3DScreenCapture* GetScreenCapture()
		{
			return pEngine->m_screenCapture.get();
		}

		static ISiv3DFont* GetFont()
		{
			return pEngine->m_font.get();
		}

		static ISiv3DPrint* GetPrint()
		{
			return pEngine->m_print.get();
		}

		static ISiv3DEffect* GetEffect()
		{
			return pEngine->m_effect.get();
		}

		static ISiv3DScript* GetScript()
		{
			return pEngine->m_script.get();
		}

		static ISiv3DAsset* GetAsset()
		{
			return pEngine->m_asset.get();
		}
	};
}
