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

# pragma once
# include <Siv3D/Platform.hpp>
# if defined(SIV3D_TARGET_WINDOWS)

# include <Siv3D/Windows.hpp>
# include <Siv3D/String.hpp>
# include <Siv3D/Window.hpp>
# include "IWindow.hpp"

namespace s3d
{
	class CWindow_Windows : public ISiv3DWindow
	{
	private:

		HWND m_hWnd = nullptr;

		std::wstring m_windowClassName;

		uint32 m_style = 0;
		
		WindowState m_state;

		Size m_baseSize = Window::DefaultClientSize;

		bool m_resizeRequest = false;

		void initState();

		bool registerWindowClass();

		bool createWindow();

	public:

		CWindow_Windows();

		~CWindow_Windows() override;

		bool init() override;

		void show(bool show) override;
		
		bool update() override;

		WindowHandle getHandle() const override;

		void setTitle(const String& title, bool forceUpdate) override;
		
		const WindowState& getState() const override;

		void setPos(const Point& pos) override;

		void updateClientSize(bool fullScreen, const Size& size) override;

		void requestResize();

		void setBaseSize(const Size& size) override;

		Size getBaseSize() const override;

		void setResizable(bool resizable) override;
	};
}

# endif
