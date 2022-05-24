/*
 * Copyright (c) 2010-2019 Belledonne Communications SARL.
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

#ifndef _L_UTILS_H_
#define _L_UTILS_H_

#include <ctime>
#include <list>
#include <regex>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <map>

#include "bctoolbox/utils.hh"

#include "linphone/utils/enum-generator.h"
#include "address/address.h"
#include "conference/session/streams.h"

// =============================================================================

LINPHONE_BEGIN_NAMESPACE

namespace Utils {
	template<typename T>
	constexpr T *getPtr (std::shared_ptr<T> &object) {
		return object.get();
	}

	template<typename T>
	constexpr T *getPtr (const std::shared_ptr<T> &object) {
		return object.get();
	}

	template<typename T>
	constexpr T *getPtr (std::unique_ptr<T> &object) {
		return object.get();
	}

	template<typename T>
	constexpr T *getPtr (const std::unique_ptr<T> &object) {
		return object.get();
	}

	template<typename T>
	constexpr T *getPtr (T *object) {
		return object;
	}

	template<typename T>
	constexpr T *getPtr (T &object) {
		return &object;
	}

	LINPHONE_PUBLIC bool iequals (const std::string &a, const std::string &b);

	LINPHONE_PUBLIC std::string toString (int val);
	LINPHONE_PUBLIC std::string toString (long val);
	LINPHONE_PUBLIC std::string toString (long long val);
	LINPHONE_PUBLIC std::string toString (unsigned val);
	LINPHONE_PUBLIC std::string toString (unsigned long val);
	LINPHONE_PUBLIC std::string toString (unsigned long long val);
	LINPHONE_PUBLIC std::string toString (float val);
	LINPHONE_PUBLIC std::string toString (double val);
	LINPHONE_PUBLIC std::string toString (long double val);
	LINPHONE_PUBLIC std::string toString (const void *val);

	template<typename T>
	LINPHONE_PUBLIC inline std::string toString (const T &val) {
		std::ostringstream ss;
		ss << val;
		return ss.str(); }

	LINPHONE_PUBLIC int stoi (const std::string &str, size_t *idx = 0, int base = 10);
	LINPHONE_PUBLIC long long stoll (const std::string &str, size_t *idx = 0, int base = 10);
	LINPHONE_PUBLIC unsigned long long stoull (const std::string &str, size_t *idx = 0, int base = 10);
	LINPHONE_PUBLIC double stod (const std::string &str, size_t *idx = 0);
	LINPHONE_PUBLIC float stof (const std::string &str, size_t *idx = 0);
	LINPHONE_PUBLIC bool stob (const std::string &str);

	LINPHONE_PUBLIC int stoi (const char *str, size_t *idx = 0, int base = 10);
	LINPHONE_PUBLIC long long stoll (const char *str, size_t *idx = 0, int base = 10);
	LINPHONE_PUBLIC unsigned long long stoull (const char *str, size_t *idx = 0, int base = 10);
	LINPHONE_PUBLIC double stod (const char *str, size_t *idx = 0);
	LINPHONE_PUBLIC float stof (const char *str, size_t *idx = 0);

	LINPHONE_PUBLIC std::string stringToLower (const std::string &str);

	LINPHONE_PUBLIC std::string unicodeToUtf8 (uint32_t ic);
	LINPHONE_PUBLIC std::string unicodeToUtf8 (const std::vector<uint32_t>& chars);

	LINPHONE_PUBLIC inline std::string cStringToCppString (const char *str) {
		return str ? str : "";
	}



	template<typename S, typename T>
	inline std::string join (const std::vector<T>& elems, const S& delim) {
		std::stringstream ss;

		for (auto e = elems.begin(); e != elems.end();) {
			if (e != elems.end()) {
				ss << *e;
			}
			if (++e != elems.end()) {
				ss << delim;
			}
		}
		return ss.str();
	}
	LINPHONE_PUBLIC std::string trim (const std::string &str);
	LINPHONE_PUBLIC std::string normalizeFilename(const std::string &str);

	template<typename T, typename std::enable_if<std::is_base_of<Address, T>::value>::type* = nullptr>
	inline const T &getEmptyConstRefObject () {
		static const T object{};
		object.removeFromLeakDetector();
		return object;
	}

	template<typename T, typename std::enable_if<!std::is_base_of<Address, T>::value>::type* = nullptr>

	inline const T &getEmptyConstRefObject () {
		return bctoolbox::Utils::getEmptyConstRefObject<T>();
	}

	template<class Container>
	inline std::vector<typename Container::value_type> toVector(const Container &l) {
		std::vector<typename Container::value_type> v;
		v.reserve(l.size());
		std::copy(std::begin(l), std::end(l), std::back_inserter(v));
		return v;
	}

	template<class Container>
	inline std::list<typename Container::value_type> toList(const Container &l) {
		std::list<typename Container::value_type> v;
		std::copy(std::begin(l), std::end(l), std::back_inserter(v));
		return v;
	}

	template<class T>
	bctbx_list_t* listToBctbxList (const std::list<T> & l) {
		bctbx_list_t* bcList = NULL;
		for (const auto & e : l) {
			bcList = bctbx_list_append(bcList, e);
		}
		return bcList;
	}

	template<class T>
	std::list<T> bctbxListToList (bctbx_list_t* l) {
		std::list<T> cppList;
		for(bctbx_list_t *elem = l;elem!=NULL;elem=elem->next){
			T data = static_cast<T>(bctbx_list_get_data(elem));
			cppList.push_back(data);
		}
		return cppList;
	}
	LINPHONE_PUBLIC std::tm getTimeTAsTm (time_t t);
	LINPHONE_PUBLIC time_t getTmAsTimeT (const std::tm &t);
	LINPHONE_PUBLIC std::string getTimeAsString (const std::string &format, time_t t);
	LINPHONE_PUBLIC time_t getStringToTime (const std::string &format, const std::string &s);

	LINPHONE_PUBLIC std::string localeToUtf8 (const std::string &str);
	LINPHONE_PUBLIC std::string utf8ToLocale (const std::string &str);
	LINPHONE_PUBLIC std::string convertAnyToUtf8 (const std::string &str, const std::string &encoding);
	LINPHONE_PUBLIC std::string quoteStringIfNotAlready(const std::string &str);

	class Version{
		public:
			LINPHONE_PUBLIC Version() = default;
			LINPHONE_PUBLIC Version(int major, int minor);
			LINPHONE_PUBLIC Version(int major, int minor, int patch);
			LINPHONE_PUBLIC Version(const std::string &version);
			
			LINPHONE_PUBLIC int compare(const Version &other) const;
			LINPHONE_PUBLIC inline bool operator<(const Version &other)const{
				return compare(other) < 0;
			}
			LINPHONE_PUBLIC inline bool operator<=(const Version &other)const{
				return compare(other) <= 0;
			}
			LINPHONE_PUBLIC inline bool operator>(const Version &other)const{
				return compare(other) > 0;
			}
			LINPHONE_PUBLIC inline bool operator>=(const Version &other)const{
				return compare(other) >= 0;
			}
			LINPHONE_PUBLIC inline bool operator==(const Version &other)const{
				return compare(other) == 0;
			}
			LINPHONE_PUBLIC inline int getMajor()const {return mMajor;};
			LINPHONE_PUBLIC inline int getMinor()const {return mMinor;};
			LINPHONE_PUBLIC inline int getPatch()const {return mPatch;};
			LINPHONE_PUBLIC inline const std::string& getPreRelease() const { return mPreRelease; };
			LINPHONE_PUBLIC inline const std::string& getBuildMetaData() const { return mBuildMetaData; };
		private:
			int mMajor = 0, mMinor = 0, mPatch = 0; 
			std::string mPreRelease;
			std::string mBuildMetaData;
	};
	
	/**
	 * Parse a capability descriptor string such our org.linphone.specs, made of comma separated keyword with optional version numbers:
	 * "lime,groupchat/1.1,ephemeral". If absent, the version number is arbitrary supposed to be 1.0.
	 */
	LINPHONE_PUBLIC std::map<std::string, Version> parseCapabilityDescriptor(const std::string &descriptor);
	std::string getSipFragAddress(const Content & content);
	std::string getResourceLists (const std::list<IdentityAddress> &addresses);
	std::list<IdentityAddress> parseResourceLists (const Content &content);
	std::shared_ptr<ConferenceInfo> createConferenceInfoFromOp (SalCallOp *op, bool remote);
}

LINPHONE_PUBLIC std::ostream &operator<<(std::ostream & ostr, const Utils::Version &version);

LINPHONE_END_NAMESPACE

#endif // ifndef _L_UTILS_H_
