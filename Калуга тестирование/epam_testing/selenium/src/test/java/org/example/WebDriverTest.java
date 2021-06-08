package org.example;
import org.junit.Assert;
import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.WebElement;
import org.openqa.selenium.chrome.ChromeDriver;
import org.openqa.selenium.support.ui.ExpectedConditions;
import org.openqa.selenium.support.ui.WebDriverWait;
import org.testng.annotations.AfterMethod;
import org.testng.annotations.BeforeMethod;
import org.testng.annotations.Test;

import java.util.List;
import java.util.concurrent.TimeUnit;

import static java.lang.Integer.parseInt;


public class WebDriverTest {
    public static final String LINK = "https://superlama.by/kulon-harry-potter";
    private WebDriver driver;

    @BeforeMethod
    public void setup(){
        driver = new ChromeDriver();
        driver.get("https://superlama.by/");
        driver.manage().window().maximize();
        driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);
    }

    @AfterMethod
    public void tearDown(){
        driver.quit();
    }

    @Test
    public void testAddedLikedItems() {

        driver.get(LINK);
        WebElement likeButton = new WebDriverWait(driver,10)
                .until(ExpectedConditions.elementToBeClickable(By.xpath("//div[@value='В корзину']")));
        likeButton.click();

        List<WebElement> likedItems = driver.findElements(By.xpath("//a[@href='https://superlama.by/kulon-harry-potter']"));
        WebElement numberOfItems = driver.findElement(By.xpath("//span[@class='cart-total']"));

        Assert.assertTrue(parseInt(numberOfItems.getText()) == likedItems.size());

    }



}