package org.example;

import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.support.FindBy;
import org.openqa.selenium.support.PageFactory;

public class RegistrationPage{
    WebDriver driver;
    final static String PAGE_URL = "https://24shop.by/personal/register.php";

    @FindBy(id = "button01")
    private WebElement registerButton;

    @FindBy(id = "01")
    private WebElement mobileInput;

    @FindBy(id = "02")
    private WebElement nameInput;

    @FindBy(id = "03")
    private WebElement emailInput;

    @FindBy(id = "04")
    private WebElement codeInput;

    //Constructor
    public RegistrationPage(WebDriver driver) {
        this.driver = driver;
//        driver.get(PAGE_URL);
        PageFactory.initElements(driver, this);
    }

    public RegistrationPage Register(String mobile, String name, String email){
        nameInput.sendKeys(name);
        mobileInput.sendKeys(mobile);
        emailInput.sendKeys(email);
        registerButton.click();
        codeInput.isEnabled();
        return this;
    }
}

