// Copyright (c) 2015-2017, The Bytecoin developers
// Copyright (c) 2022, The SoM developers
//
// This file is part of Karbo.
//
// Karbovanets is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Karbovanets is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with Karbovanets.  If not, see <http://www.gnu.org/licenses/>.

#include "InProcessNodeAdapter.h"
#include "InProcessNodeWorker.h"
#include "WalletGreenAdapter.h"

namespace WalletGui {

InProcessNodeAdapter::InProcessNodeAdapter(const CryptoNote::Currency& _currency, Logging::ILogger& _loggerManager, Logging::ILogger& _walletLogger,
  QObject* _parent) : CommonNodeAdapter(_parent), m_currency(_currency), m_loggerManager(_loggerManager), m_walletLogger(_walletLogger) {
}

InProcessNodeAdapter::~InProcessNodeAdapter() {
}

INodeAdapter* InProcessNodeAdapter::createWorker() const {
  return new InProcessNodeWorker(m_currency, m_loggerManager, m_walletLogger, nullptr);
}

}
