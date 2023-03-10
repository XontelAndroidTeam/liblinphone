/*
 * Copyright (c) 2010-2022 Belledonne Communications SARL.
 *
 * This file is part of Liblinphone 
 * (see https://gitlab.linphone.org/BC/public/liblinphone).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
package org.linphone.core.tools;

public final class Log {
    private static Log logger;
    private static String domain = "linphone-android";

    private static Log instance() {
        if (logger == null) {
            logger = new Log();
            logger.setLogDomain(domain);
        }
        return logger;
    }

    private Log() {
    }

    private native void setDomain(String logDomain);

    public static void setLogDomain(String logDomain) {
        Log.instance().setDomain(logDomain);
        Log.domain = logDomain;
    }

    private native void d(String domain, String msg);

    public static void d(Object... objects) {
        Log.instance().d(Log.domain, toString(objects));
    }

    private native void i(String domain, String msg);

    public static void i(Object... objects) {
        Log.instance().i(Log.domain, toString(objects));
    }

    private native void w(String domain, String msg);

    public static void w(Object... objects) {
        Log.instance().w(Log.domain, toString(objects));
    }

    private native void e(String domain, String msg);

    public static void e(Object... objects) {
        Log.instance().e(Log.domain, toString(objects));
    }

    private native void f(String domain, String msg);

    public static void f(Object... objects) {
        Log.instance().f(Log.domain, toString(objects));
    }

    private static String toString(Object... objects) {
        StringBuilder sb = new StringBuilder();
        for (Object o : objects) {
            sb.append(o);
        }
        return sb.toString();
    }
}


