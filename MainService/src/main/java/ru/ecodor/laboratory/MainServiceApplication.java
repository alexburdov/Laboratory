package ru.ecodor.laboratory;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class MainServiceApplication {

    public static void main(String[] args) {
    /*    ConfigurableApplicationContext context = SpringApplication.run(MainServiceApplication.class, args);
        LicenseService licenseService = context.getBean(LicenseService.class);
        licenseService.createLicenseKeyFromComputer("3431366537393262346437393262353336353633373236353734326237333631366337343262326234363635633332373239386331366135373465366161626362316336333862343439663863666131393165646230346563346634306532613832663032343863");
        context.close(); // Close the context when done
    */

        SpringApplication.run(MainServiceApplication.class, args);
//        String a = LicenseServiceLibrary.INSTANCE.getLicenseKey();
//        String b = LicenseServiceLibrary.INSTANCE.getCompGuid();
//        System.out.println(a + "\n" + b);
    }
}
