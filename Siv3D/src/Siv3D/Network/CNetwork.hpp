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
# include "INetwork.hpp"
# include <Siv3D/Network.hpp>

namespace s3d
{
	class CNetwork : public ISiv3DNetwork
	{
	private:

		Optional<IPv4> m_machineIP;
	
	public:

		CNetwork();

		~CNetwork() override;

		bool init() override;

		Optional<IPv4> getMachineIP() const override;
	};
}
