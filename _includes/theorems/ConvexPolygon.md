



A __convex polygon__ is a polygon where, for any two points in or on the polygon, the line between those points is contained within the polygon.



**Theorem:** For any convex polygon with n vertices, the sum of the angles in that polygon is (n – 2) · 180°

 By induction. 
 
 Let P(n) be "all convex polygons with n vertices have angles that sum to (n – 2) · 180°." 

  We will prove P(n) holds for all n ∈ ℕ where n ≥ 3.

Basis

As a base case, we prove P(3): the sum of the angles in any convex polygon with three vertices is 180°. Any such polygon is a triangle, so its angles sum to 180°. 

For the inductive step, assume for some n ≥ 3 that 

P(n) holds and all convex polygons with n vertices have angles that sum to (n–2) · 180°.

We prove P(n+1), that the sum of the angles in any convex polygon with n+1 vertices is (n–1) · 180°. 
Let A be an arbitrary convex polygon with n+1 vertices. Take any three consecutive vertices in A


The sum of the angles in A is equal to the sum of the angles in triangle B (180°) 
and the sum of the angles in convex polygon C (which, by the IH, is (n – 2) · 180°). Therefore, the sum of the angles in A is (n–1) · 180°. Thus P(n + 1) holds, completing the induction




