package ru.ecodor.laboratory.services.impl;

import org.springframework.stereotype.Service;
import ru.ecodor.laboratory.exceptions.CreateLicenseFileException;
import ru.ecodor.laboratory.services.LicenseService;
import ru.ecodor.laboratory.jna.LicenseServiceLibrary;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.Objects;

import static ru.ecodor.laboratory.commons.Constants.*;

@Service
public class LicenseServiceImpl implements LicenseService {

    String license = getLicenseKeyFromComputer();

    @Override
    public boolean isLicenseValid() {
        String current = LicenseServiceLibrary.INSTANCE.getLicenseKey();
        if (Objects.isNull(license) || license.isEmpty()) {
            return false;
        }
        return license.equals(current);
    }

    @Override
    public String getLicenseKey() {
        return LicenseServiceLibrary.INSTANCE.getLicenseKey();
    }

    @Override
    public String getComputerGuid() {
        return LicenseServiceLibrary.INSTANCE.getCompGuid();
    }

    private String getLicenseKeyFromComputer() {
        String appDataPath = System.getenv(APP_DATA);
        if (Objects.isNull(appDataPath) || appDataPath.isEmpty()) {
            return NOT_LICENSE;
        }
        String appFolder = appDataPath + File.separator + ECODOR_FOLDER;
        if (!Files.exists(Paths.get(appFolder))) {
            return NOT_LICENSE;
        }
        String licenseFilePath = appFolder + File.separator + LICENSE_FILE;
        if (!Files.exists(Paths.get(licenseFilePath))) {
            return NOT_LICENSE;
        }
        File licenseFile = new File(licenseFilePath);

        if (licenseFile.exists() && licenseFile.isFile()) {
            try (BufferedReader reader = new BufferedReader(new FileReader(licenseFile))) {
                String line;
                if ((line = reader.readLine()) != null) {
                    return line;
                }
                return NOT_LICENSE;
            } catch (IOException e) {
                return NOT_LICENSE;
            }
        }
        return NOT_LICENSE;
    }

    public void setLicenseKey(String licenseKey) {
        String appDataPath = System.getenv(APP_DATA);
        try {
            if (Objects.isNull(appDataPath) || appDataPath.isEmpty()) {
                Files.createDirectories(Paths.get(appDataPath));
            }
            String appFolder = appDataPath + File.separator + ECODOR_FOLDER;
            if (!Files.exists(Paths.get(appFolder))) {
                Files.createDirectories(Paths.get(appFolder));
            }

            String licenseFilePath = appFolder + File.separator + LICENSE_FILE;
            if (!Files.exists(Paths.get(licenseFilePath))) {
                Files.createFile(Paths.get(licenseFilePath));
            } else {
                Paths.get(licenseFilePath);
            }
            try (FileWriter writer = new FileWriter(licenseFilePath)) {
                writer.write(licenseKey);
            }
        } catch (IOException e) {
            throw new CreateLicenseFileException(e);
        }
    }
}
