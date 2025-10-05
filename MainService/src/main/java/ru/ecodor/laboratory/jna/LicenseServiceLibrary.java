package ru.ecodor.laboratory.jna;

import com.sun.jna.Library;
import com.sun.jna.Native;

public interface LicenseServiceLibrary extends Library {
    LicenseServiceLibrary INSTANCE = Native.load("LicenseServiceLibrary", LicenseServiceLibrary.class);

    String getLicenseKey();

    String getCompGuid();
}
