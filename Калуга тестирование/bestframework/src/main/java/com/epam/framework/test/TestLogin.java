package com.epam.framework.test;

import com.epam.framework.model.User;
import com.epam.framework.page.LoginPage;
import com.epam.framework.page.ProductsPage;
import com.epam.framework.page.SearchPage;
import com.epam.framework.service.ProductHandler;
import com.epam.framework.service.ReadEnvSpecificData;
import org.testng.Assert;
import org.testng.annotations.Test;

import java.util.ResourceBundle;

public class TestLogin extends CommonConditions{

    @Test
    public void loginUserTest() {
        var user = new User(ReadEnvSpecificData.getTestData("test_data.user.mobile"), ReadEnvSpecificData.getTestData("test_data.user.password"));
        Assert.assertEquals(user.getMobile(), "445474951");
        Assert.assertEquals(user.getPassword(), "password");
        Assert.assertTrue(new LoginPage(driver).openPage().loginUser(user).isUserLoggedIn());
    }
}
