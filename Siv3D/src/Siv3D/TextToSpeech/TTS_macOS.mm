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

# include "CTextToSpeech_macOS.hpp"
# include "TTS_macOS.h"
# include <Siv3D/LanguageCode.hpp>

namespace s3d
{
	namespace detail
	{
		inline constexpr float ConvertSpeed(const double speed)
		{
			return static_cast<float>(200 + (std::clamp(speed, 0.0, 2.0) - 1.0) * 100);
		}
		
		NSString* ConvertLanguageCode(const int32 languageCode)
		{
			// [Siv3D ToDo] more languages!
			switch (languageCode)
			{
			case LanguageCode::ArabicSA:
				return @"com.apple.speech.synthesis.voice.tarik";
			case LanguageCode::ChineseCN:
				return @"com.apple.speech.synthesis.voice.ting-ting";
			case LanguageCode::ChineseHK:
				return @"com.apple.speech.synthesis.voice.sin-ji";
			case LanguageCode::ChineseTW:
				return @"com.apple.speech.synthesis.voice.mei-Jia";
			case LanguageCode::EnglishAU:
				return @"com.apple.speech.synthesis.voice.karen";
			case LanguageCode::EnglishGB:
				return @"com.apple.speech.synthesis.voice.daniel";
			case LanguageCode::EnglishUS:
				return @"com.apple.speech.synthesis.voice.Alex";
			case LanguageCode::FrenchFR:
				return @"com.apple.speech.synthesis.voice.thomas";
			case LanguageCode::GermanDE:
				return @"com.apple.speech.synthesis.voice.anna";
			case LanguageCode::HindiIN:
				return @"com.apple.speech.synthesis.voice.lekha";
			case LanguageCode::ItalianIT:
				return @"com.apple.speech.synthesis.voice.alice";
			case LanguageCode::Japanese:
				return @"com.apple.speech.synthesis.voice.kyoko";
			case LanguageCode::Korean:
				return @"com.apple.speech.synthesis.voice.yuna";
			case LanguageCode::PortugueseBR:
				return @"com.apple.speech.synthesis.voice.luciana";
			case LanguageCode::RussianRU:
				return @"com.apple.speech.synthesis.voice.milena";
			case LanguageCode::SpanishES:
				return @"com.apple.speech.synthesis.voice.monica";
			default:
				return nil;
			}
		}
	}
	
	CTextToSpeech_macOS::CTextToSpeechDetail::CTextToSpeechDetail()
		: m_detail(std::make_unique<TTS_macOS>())
	{
		
	}
	
	CTextToSpeech_macOS::CTextToSpeechDetail::~CTextToSpeechDetail()
	{
		
	}
	
	bool CTextToSpeech_macOS::CTextToSpeechDetail::hasLanguage(const int32 languageCode)
	{
		return m_detail->hasLanguage(languageCode);
	}
	
	void CTextToSpeech_macOS::CTextToSpeechDetail::setDefaultLanguage(const int32 languageCode)
	{
		m_detail->setDefaultLanguage(languageCode);
	}
	
	int32 CTextToSpeech_macOS::CTextToSpeechDetail::getDefaultLanguage() const
	{
		return m_detail->getDefaultLanguage();
	}
	
	bool CTextToSpeech_macOS::CTextToSpeechDetail::speak(const std::string& text, const int32 languageCode)
	{
		return m_detail->speak(text, languageCode);
	}
	
	bool CTextToSpeech_macOS::CTextToSpeechDetail::isSpeaking() const
	{
		return m_detail->isSpeaking();
	}
	
	void CTextToSpeech_macOS::CTextToSpeechDetail::pause()
	{
		m_detail->pause();
	}
	
	void CTextToSpeech_macOS::CTextToSpeechDetail::resume()
	{
		m_detail->resume();
	}
	
	void CTextToSpeech_macOS::CTextToSpeechDetail::setVolume(const double volume)
	{
		m_detail->setVolume(volume);
	}
	
	double CTextToSpeech_macOS::CTextToSpeechDetail::getVolume() const
	{
		return m_detail->getVolume();
	}
	
	void CTextToSpeech_macOS::CTextToSpeechDetail::setSpeed(const double speed)
	{
		m_detail->setSpeed(speed);
	}
	
	double CTextToSpeech_macOS::CTextToSpeechDetail::getSpeed() const
	{
		return m_detail->getSpeed();
	}
	
	TTS_macOS::~TTS_macOS()
	{
		reset();
	}
	
	bool TTS_macOS::hasLanguage(const int32 languageCode)
	{
		NSSpeechSynthesizer* tmp = [[NSSpeechSynthesizer alloc] initWithVoice:nil];
		const bool result = [tmp setVoice: detail::ConvertLanguageCode(languageCode)];
		[tmp release];
		return result;
	}
	
	void TTS_macOS::setDefaultLanguage(const int32 languageCode)
	{
		m_defaultLanguageCode = languageCode;
	}
	
	int32 TTS_macOS::getDefaultLanguage() const
	{
		return m_defaultLanguageCode;
	}
	
	bool TTS_macOS::speak(const std::string& text, int32 languageCode)
	{
		reset();
		
		if (languageCode == 0)
		{
			languageCode = m_defaultLanguageCode;
		}
		
		m_speechSynth = [[NSSpeechSynthesizer alloc] initWithVoice:nil];
		
		[m_speechSynth setVoice: detail::ConvertLanguageCode(languageCode)];
		[m_speechSynth setVolume:m_volume];
		[m_speechSynth setRate:detail::ConvertSpeed(m_speed)];

		NSString* text_ns = [NSString stringWithUTF8String:text.c_str()];
		[m_speechSynth startSpeakingString:text_ns];

		return true;
	}

	bool TTS_macOS::isSpeaking() const
	{
		return [m_speechSynth isSpeaking];
	}
	
	void TTS_macOS::reset()
	{
		if (!m_speechSynth)
		{
			return;
		}
		
		[m_speechSynth stopSpeaking];
		[m_speechSynth release];
		m_speechSynth = nil;
	}
	
	void TTS_macOS::pause()
	{
		if (!m_speechSynth)
		{
			return;
		}

		[m_speechSynth pauseSpeakingAtBoundary:NSSpeechImmediateBoundary];
	}
	
	void TTS_macOS::resume()
	{
		if (!m_speechSynth)
		{
			return;
		}
		
		[m_speechSynth continueSpeaking];
	}
	
	void TTS_macOS::setVolume(const double volume)
	{
		m_volume = std::clamp(volume, 0.0, 1.0);
		
		if (m_speechSynth)
		{
			[m_speechSynth setVolume:m_volume];
		}
	}
	
	double TTS_macOS::getVolume() const
	{
		return m_volume;
	}
	
	void TTS_macOS::setSpeed(const double speed)
	{
		m_speed = std::clamp(speed, 0.0, 2.0);
		
		if (m_speechSynth)
		{
			[m_speechSynth setRate:detail::ConvertSpeed(m_speed)];
		}
	}
	
	double TTS_macOS::getSpeed() const
	{
		return m_speed;
	}
}

