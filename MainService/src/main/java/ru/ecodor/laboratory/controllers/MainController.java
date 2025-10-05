package ru.ecodor.laboratory.controllers;

import lombok.extern.slf4j.Slf4j;
import org.springframework.http.HttpStatusCode;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/")
@Slf4j
public class MainController {

    @GetMapping("/")
    public ResponseEntity<String> echo() {
        return new ResponseEntity<>("Echo", HttpStatusCode.valueOf(200));
    }
}
