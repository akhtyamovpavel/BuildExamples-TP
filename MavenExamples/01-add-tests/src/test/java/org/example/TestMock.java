package org.example;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.TestInstance;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.chrome.ChromeDriver;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.mockito.Mockito.*;

@TestInstance(TestInstance.Lifecycle.PER_CLASS)
public class TestMock {
    private WebDriver driver;

    @BeforeAll
    public void initBrowser() {
        this.driver = mock(ChromeDriver.class);
    }

    @AfterAll
    public void closeBrowser() {
        this.driver.quit();
    }

    @Test
    public void testWebHse() throws InterruptedException {
        when(this.driver.getTitle()).thenReturn("Mock");
        driver.get("https://www.hse.ru/en/");

        Thread.sleep(1000);
        assertEquals("Mock", driver.getTitle());

        verify(this.driver, atLeastOnce()).get(any());

    }

    @Test
    public void testWebYa() throws InterruptedException {
        when(this.driver.getTitle()).thenReturn("Mock2");
        driver.get("https://ya.ru/");

        Thread.sleep(1000);
        assertEquals("Mock2", driver.getTitle());
    }
}
