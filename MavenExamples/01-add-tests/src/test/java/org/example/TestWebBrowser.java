package org.example;

import org.junit.jupiter.api.*;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

import static org.junit.jupiter.api.Assertions.assertEquals;


@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestWebBrowser {

    private WebDriver driver;

    @BeforeAll
    public void initBrowser() {
        this.driver = new ChromeDriver();
    }

    @AfterAll
    public void closeBrowser() {
        this.driver.quit();
    }

    @Test
    public void testWebHse() throws InterruptedException {
        driver.get("https://www.hse.ru/en/");

        Thread.sleep(10000);
        assertEquals("HSE University", driver.getTitle());
    }

    @Test
    public void testWebYa() throws InterruptedException {
        driver.get("https://ya.ru/");

        Thread.sleep(10000);
        assertEquals("Яндекс", driver.getTitle());
    }


}
