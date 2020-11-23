package ref;

public class AssetJ {
    

    assertThat(actualProduct)
    .isEqualToIgnoringGivenFields(expectedProduct, "id");

assertThat(actualProductList).containsExactly(
    createProductDTO("1", "Smartphone", 250.00),
    createProductDTO("1", "Smartphone", 250.00)
);

assertThat(actualProductList)
    .usingElementComparatorIgnoringFields("id")
    .containsExactly(expectedProduct1, expectedProduct2);

assertThat(actualProductList)
    .extracting(Product::getId)
    .containsExactly("1", "2");

assertThat(actualProductList)
    .anySatisfy(product -> assertThat(product.getDateCreated()).isBetween(instant1, instant2));

assertThat(actualProductList)
    .filteredOn(product -> product.getCategory().equals("Smartphone"))
    .allSatisfy(product -> assertThat(product.isLiked()).isTrue());
    
    
    assertThatExceptionOfType(IOException.class).isThrownBy(() -> { throw new IOException("boom!"); })
    .withMessage("%s!", "boom")
    .withMessageContaining("boom")
    .withNoCause();

}

fun main () { 
    await.timeout(5, TimeUnit.SECONDS).untilAsserted {
        assertThat(atomicInteger.get()).isEqualTo(totalMessages)
    }



    testImplementation("org.awaitility:awaitility:2.0.0")
    testImplementation("org.awaitility:awaitility-kotlin:4.0.1")
    testImplementation("org.assertj:assertj-core:$assertJVersion")

}




SoftAssertions softly = new SoftAssertions();
softly.assertThat(rectangle.getLength()).isEqualTo(length);
softly.assertThat(rectangle.getWidth()).isEqualTo(width);
softly.assertThat(rectangle.area()).isEqualTo(6);
softly.assertThat(rectangle.perimeter()).isEqualTo(10);
softly.assertAll();
