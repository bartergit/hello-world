package org.example;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;

public class MainPage {
    private WebDriver driver;
    private static String PAGE_URL = "https://24shop.by/";

    @FindBy(css = ".top-nav-menu--auth div:first-child a")
    private WebElement registerLink;

    public MainPage(WebDriver driver) {
        this.driver = driver;
        driver.get(PAGE_URL);
        PageFactory.initElements(driver, this);
    }

    public RegistrationPage clickOnRegisterLink() throws Exception {
        registerLink.click();
        if (!driver.getCurrentUrl().equals(RegistrationPage.PAGE_URL))
            throw new Exception("no valid page returned");
        return new RegistrationPage(driver);
    }
}