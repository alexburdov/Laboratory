package ru.ecodor.laboratory.services;

public interface LicenseService {

    boolean isLicenseValid();

    String getLicenseKey();

    String getComputerGuid();

    void setLicenseKey(String licenseKey);
}
