# x86-to-C Interface
**Input:** Scalar variable n (integer) contains the length of the vector; Vectors X and Y are both single-precision float. <br>
**Process:** $`Y[i] = X[i - 3] + X[i - 2] + X[i - 1] + X[i] + X[i + 1] + X[i + 2] + X[i + 3]`$ <br>
**Output:** Store result in vector Y. Display the result of 1st ten elements of vector Y for all versions of kernel (i.e., C and x86-64).
### Debug Mode
#### Vector size n = 2<sup>20</sup>
<img src="/screenshots/debug/20/debug_20_1.jpg" width="250"/> <img src="/screenshots/debug/20/debug_20_6.jpg" width="250"/>
#### Vector size n = 2<sup>24</sup>
<img src="/screenshots/debug/24/debug_24_1.jpg" width="250"/> <img src="/screenshots/debug/24/debug_24_6.jpg" width="250"/>
#### Vector size n = 2<sup>28</sup>
<img src="/screenshots/debug/28/debug_28_1.jpg" width="250"/> <img src="/screenshots/debug/28/debug_28_6.jpg" width="250"/>
---
### Release Mode
#### Vector size n = 2<sup>20</sup>
#### Vector size n = 2<sup>24</sup>
#### Vector size n = 2<sup>28</sup>
---
### Conclusion
