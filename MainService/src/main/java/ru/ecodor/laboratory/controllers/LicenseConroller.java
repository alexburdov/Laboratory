package ru.ecodor.laboratory.controllers;


import lombok.extern.slf4j.Slf4j;
import org.springframework.http.HttpStatusCode;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import ru.ecodor.laboratory.services.LicenseService;

@RestController
@RequestMapping("/license")
@Slf4j
public class LicenseConroller {

    private final LicenseService licenseService;

    public LicenseConroller(LicenseService licenseService) {
        this.licenseService = licenseService;
    }

    @GetMapping("/echo")
    public ResponseEntity<String> echo() {
        return new ResponseEntity<>("License Echo", HttpStatusCode.valueOf(200));
    }

    @GetMapping("/computerId")
    public ResponseEntity<String> computerId() {
        String computerId = licenseService.getComputerGuid();
        return new ResponseEntity<>(computerId, HttpStatusCode.valueOf(200));
    }

    @PostMapping("/set")
    public void setLicenseKey(@RequestBody String licenseKey) {
        licenseService.setLicenseKey(licenseKey);
    }
}
