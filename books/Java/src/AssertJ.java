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
    
    
}