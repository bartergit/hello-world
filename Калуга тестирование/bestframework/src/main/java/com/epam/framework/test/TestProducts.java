package com.epam.framework.test;

import com.epam.framework.page.ProductsPage;
import com.epam.framework.service.ProductHandler;
import org.testng.Assert;
import org.testng.annotations.Test;

public class TestProducts extends CommonConditions {
    @Test
    public void testSortByPriceInc() {
        Assert.assertTrue(ProductHandler
                .isSortedByPriceInc(new ProductsPage(driver)
                        .openPage()
                        .getProductsSortByPriceInc()));
    }

    @Test
    public void testSortByPriceDec() {
        Assert.assertTrue(ProductHandler
                .isSortedByPriceDec(new ProductsPage(driver)
                        .openPage()
                        .getProductsSortByPriceDec()));
    }

    @Test void testSortByCategories(){
        Assert.assertTrue(ProductHandler.containsProductWithName(new ProductsPage(driver)
                .openPage()
                .sortByCategory("Samsung"), "samsung"));
    }
}
