# Detection 

In this draft, I am trying to detect the input stitch type being made by the user.

# Data collection details

For a single stitch type, we collect a ypr (yaw, pitch, roll) data from an gyro connected to arduino for around 3 minutes. 
A user repeats the same type of stitch throughout these three minutes. Different versions (slow, fast, different yarn thickness) are collected.

We collect dat for each of designated crochet stitch types:
* __chain (ch)__: yarn over, pull through
* __single crochet (sc)__: insert hook, yarn over, pull through, yarn over, pull through two
* __half double crochet (hdc)__: yarn over, insert hook, yarn over, pull through, yarn over, pull through three
* __double crochet  (dc)__: yarn over, insert hook, yarn over, pull through, yarn over, pull through two, yarn over, pull through two
* __treble crochet (tr)__: yarn over twice, insert hook, yarn over, pull through, yarn over, pull through two, yarn over, pull through two, yarn over, pull through two

# Edge Impulse

I use edgeimpulse.com to build my model - it's convinient. I followed all the instructions from their platform. 

# Arduino Libraries Used

* [I2Cdev](https://github.com/jrowberg/i2cdevlib) - download and unzip. Load /Arduino/I2Cdev and /Arduino/MPU6050 as libraries in .zip form.
