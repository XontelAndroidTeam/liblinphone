############################################################################
# CMakeLists.txt
# Copyright (c) 2010-2022 Belledonne Communications SARL.
#
############################################################################
#
# This file is part of Liblinphone 
# (see https://gitlab.linphone.org/BC/public/liblinphone).
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as
# published by the Free Software Foundation, either version 3 of the
# License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program. If not, see <http://www.gnu.org/licenses/>.
############################################################################

add_subdirectory(doxygen)

if(ENABLE_JAVADOC)
		find_package(Java REQUIRED)
		set(JAVADOC_PACKAGES "org.linphone.core org.linphone.mediastream")
		set(JAVADOC_CLASSPATHS
				"${PROJECT_SOURCE_DIR}/java/common"
				"${PROJECT_SOURCE_DIR}/java/j2se"
				"${PROJECT_SOURCE_DIR}/mediastreamer2/java/src"
		)
		string(REPLACE ";" ":" JAVADOC_CLASSPATHS "${JAVADOC_CLASSPATHS}")
		set(JAVADOC_TITLE "Linphone SDK ${PROJECT_VERSION} reference documentation")
		set(JAVADOC_JAVA_REFERENCE "http://docs.oracle.com/javase/8/docs/api/")
		set(JAVADOC_OUTPUT_DIR "${CMAKE_CURRENT_BINARY_DIR}/doc/java")
		set(JAVADOC_LOGFILE "${CMAKE_CURRENT_BINARY_DIR}/javadoc.log")
		configure_file("generate_javadoc.sh.in" "generate_javadoc.sh" @ONLY)
		add_custom_target(javadoc ALL
				COMMAND "${CMAKE_CURRENT_BINARY_DIR}/generate_javadoc.sh"
		)
endif()
