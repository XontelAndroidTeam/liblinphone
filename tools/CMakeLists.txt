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

set(USE_BUNDLE )
if (IOS)
	set(USE_BUNDLE MACOSX_BUNDLE)
endif()

set(LP_AUTO_ANSWER_SOURCE_FILES	auto_answer.c)
bc_apply_compile_flags(LP_AUTO_ANSWER_SOURCE_FILES STRICT_OPTIONS_CPP STRICT_OPTIONS_C)
add_executable(lp-auto-answer ${USE_BUNDLE} ${LP_AUTO_ANSWER_SOURCE_FILES})
target_link_libraries(lp-auto-answer ${LINPHONE_LIBS_FOR_TOOLS} mediastreamer ortp bctoolbox ${XSD_LIBRARIES})
set_target_properties(lp-auto-answer PROPERTIES LINK_FLAGS "${LINPHONE_LDFLAGS}")
set_target_properties(lp-auto-answer PROPERTIES LINKER_LANGUAGE CXX)

set(LP_SENDMSG_SOURCE_FILES lpsendmsg.c)
bc_apply_compile_flags(LP_SENDMSG_SOURCE_FILES STRICT_OPTIONS_CPP STRICT_OPTIONS_C)
add_executable(lp-sendmsg ${USE_BUNDLE} ${LP_SENDMSG_SOURCE_FILES})
target_link_libraries(lp-sendmsg ${LINPHONE_LIBS_FOR_TOOLS} ortp mediastreamer ${XSD_LIBRARIES})
set_target_properties(lp-sendmsg PROPERTIES LINK_FLAGS "${LINPHONE_LDFLAGS}")
set_target_properties(lp-sendmsg PROPERTIES LINKER_LANGUAGE CXX)

set(LP_LPC2XML_TEST_SOURCE_FILES lpc2xml_test.c)
bc_apply_compile_flags(LP_LPC2XML_TEST_SOURCE_FILES STRICT_OPTIONS_CPP STRICT_OPTIONS_C)
add_executable(lpc2xml_test ${USE_BUNDLE} ${LP_LPC2XML_TEST_SOURCE_FILES})
target_link_libraries(lpc2xml_test ${LINPHONE_LIBS_FOR_TOOLS} ortp mediastreamer ${XSD_LIBRARIES})
set_target_properties(lpc2xml_test PROPERTIES LINK_FLAGS "${LINPHONE_LDFLAGS}")
set_target_properties(lpc2xml_test PROPERTIES LINKER_LANGUAGE CXX)

set(LP_XML2LPC_TEST_SOURCE_FILES xml2lpc_test.c)
bc_apply_compile_flags(LP_XML2LPC_TEST_SOURCE_FILES STRICT_OPTIONS_CPP STRICT_OPTIONS_C)
add_executable(xml2lpc_test ${USE_BUNDLE} ${LP_XML2LPC_TEST_SOURCE_FILES})
target_link_libraries(xml2lpc_test ${LINPHONE_LIBS_FOR_TOOLS} ortp mediastreamer ${XSD_LIBRARIES})
set_target_properties(xml2lpc_test PROPERTIES LINK_FLAGS "${LINPHONE_LDFLAGS}")
set_target_properties(xml2lpc_test PROPERTIES LINKER_LANGUAGE CXX)

set(LP_TEST_ECC_SOURCE_FILES test_ecc.c)
bc_apply_compile_flags(LP_TEST_ECC_SOURCE_FILES STRICT_OPTIONS_CPP STRICT_OPTIONS_C)
add_executable(lp-test-ecc ${USE_BUNDLE} ${LP_TEST_ECC_SOURCE_FILES})
target_link_libraries(lp-test-ecc ${LINPHONE_LIBS_FOR_TOOLS} ortp mediastreamer bctoolbox ${XSD_LIBRARIES})
set_target_properties(lp-test-ecc PROPERTIES LINK_FLAGS "${LINPHONE_LDFLAGS}")
set_target_properties(lp-test-ecc PROPERTIES LINKER_LANGUAGE CXX)

if (NOT IOS)
	install(TARGETS lp-auto-answer lp-sendmsg lpc2xml_test xml2lpc_test lp-test-ecc
		RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
		LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
		ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
		PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
		)
endif()
