

/*
 Copyright (C) 2000, 2001, 2002 RiskMap srl

 This file is part of QuantLib, a free-software/open-source library
 for financial quantitative analysts and developers - http://quantlib.org/

 QuantLib is free software: you can redistribute it and/or modify it under the
 terms of the QuantLib license.  You should have received a copy of the
 license along with this program; if not, please email ferdinando@ametrano.net
 The license is also available online at http://quantlib.org/html/license.html

 This program is distributed in the hope that it will be useful, but WITHOUT
 ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 FOR A PARTICULAR PURPOSE.  See the license for more details.
*/
/*! \file xibormanager.cpp
    \brief global repository for %Xibor histories

    \fullpath
    ql/Indexes/%xibormanager.cpp
*/

// $Id$

#include <ql/Indexes/xibormanager.hpp>

namespace QuantLib {

    namespace Indexes {

        XiborManager::HistoryMap XiborManager::historyMap_;

        void XiborManager::setHistory(const std::string& name,
            const History& history) {
                historyMap_[name] = history;
        }

        const History& XiborManager::getHistory(const std::string& name) {
            XiborManager::HistoryMap::const_iterator i =
                historyMap_.find(name);
            QL_REQUIRE(i != historyMap_.end(),
                name + " history not loaded");
            return i->second;
        }

        bool XiborManager::hasHistory(const std::string& name) {
            return (historyMap_.find(name) != historyMap_.end());
        }

        std::vector<std::string> XiborManager::histories() {
            std::vector<std::string> temp;
            XiborManager::HistoryMap::const_iterator i;
            for (i = historyMap_.begin(); i != historyMap_.end(); i++)
                temp.push_back(i->first);
            return temp;
        }

    }

}

