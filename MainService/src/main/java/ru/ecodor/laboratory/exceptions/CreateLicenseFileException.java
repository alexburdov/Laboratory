package ru.ecodor.laboratory.exceptions;

public class CreateLicenseFileException extends RuntimeException {
    private static final String CREATE_LICENSE_FILE_EXCEPTION_MESSAGE = "Error creating license";
    public CreateLicenseFileException(Exception e) {
        super(CREATE_LICENSE_FILE_EXCEPTION_MESSAGE, e);
    }
}
