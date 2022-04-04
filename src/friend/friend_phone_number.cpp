/*
 * Copyright (c) 2010-2022 Belledonne Communications SARL.
 *
 * This file is part of Liblinphone.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "friend_phone_number.h"
#include "linphone/api/c-friend-phone-number.h"

using namespace std;

LINPHONE_BEGIN_NAMESPACE

FriendPhoneNumber::FriendPhoneNumber (const string &phoneNumber, const string label) {
    mLabel = label;
    mPhoneNumber = phoneNumber;
}

FriendPhoneNumber::FriendPhoneNumber (const string &phoneNumber): FriendPhoneNumber(phoneNumber, "") {
    
}

FriendPhoneNumber::FriendPhoneNumber (const std::shared_ptr<belcard::BelCardPhoneNumber>& belcardPhoneNumber) {
    mLabel = belcardPhoneNumber->getTypeParam()->getValue();
    mPhoneNumber = belcardPhoneNumber->getValue();
}

FriendPhoneNumber::FriendPhoneNumber (const FriendPhoneNumber &other) : HybridObject(other) {
    
}

FriendPhoneNumber::~FriendPhoneNumber () {

}

// -----------------------------------------------------------------------------

FriendPhoneNumber* FriendPhoneNumber::clone () const {
	return new FriendPhoneNumber(*this);
}

shared_ptr<belcard::BelCardPhoneNumber> FriendPhoneNumber::toBelcardPhoneNumber() const {
    shared_ptr<belcard::BelCardPhoneNumber> phoneNumber = belcard::BelCardGeneric::create<belcard::BelCardPhoneNumber>();
    phoneNumber->setValue(mPhoneNumber);
    if (!mLabel.empty()) {
        shared_ptr<belcard::BelCardTypeParam> label = belcard::BelCardGeneric::create<belcard::BelCardTypeParam>();
        label->setName("TYPE");
        label->setValue(mLabel);
        phoneNumber->setTypeParam(label);
    }
    return phoneNumber;
}

// -----------------------------------------------------------------------------

void FriendPhoneNumber::setPhoneNumber(const std::string& phoneNumber) {
    mPhoneNumber = phoneNumber;
}

const std::string& FriendPhoneNumber::getPhoneNumber() const {
    return mPhoneNumber;
}

void FriendPhoneNumber::setLabel(const std::string& label) {
    mLabel = label;
}

const std::string& FriendPhoneNumber::getLabel() const {
    return mLabel;
}

// -----------------------------------------------------------------------------

LINPHONE_END_NAMESPACE