# Cotton Weed Detection and Early Targeting System for Autonomous Herbicide Spraying with Visual Servoing on Jetson Nano <br> <br> 


## This project is a part of a research paper titled: 
"Development of a Detection and Automatic Targeting System for Cotton WeedWeeds using an Improved Lightweight YOLOv8 Architecture on an Edge Device" (Under Review)



## Abstract
<div style="text-align: justify">
Weeds deplete production and increase pest and disease risks by competing with crops for resources. Conventional weed-removal techniques are expensive, time-consuming, and bad for the environment. YOLO and other forms of modern picture processing provide revolutionary answers. This work presents a modified YOLOv8 architecture with CBAM and C2Ghost module trained on an augmented CottonWeedDet12 dataset, specifically designed for edge devices. With only 3.6 million parameters, the model achieves an impressive mAP@50 score of 97.6%, effectively classifying 12 different types of cotton weed. The interpretability of AI is validated by XAI approaches. Furthermore, a targeting system was created that promises autonomy in weed management. It allows for automatic weed tracking and pesticide spraying with visual servoing. For small-scale farmers, lightweight versions of gadgets like the Jetson Nano improve accessibility and encourage sustainable farming methods.
</div>

### Installation of Ultalytics on Jetson Nano
There are two ways you can do it on the Jetson Nano platform. The better one is shown here. The latest Jetpack Version of Jetson Nano B01 is 4.6.1 which comes with a Python version of 3.6, which is not supported by YOLOv8. 

#### Process of installation

There is a website where you can get to know the process of flashing Ubuntu 20.04 on Jetson Nano [here](https://github.com/Qengineering/Jetson-Nano-Ubuntu-20-image). It will install Python 3.8 as well as different important machine-learning libraries without any version conflict. Make sure to take a look at the process on this webpage. It's easy. You can find the image here.  ![Example Image](images/example.png)
Password: "jetson"

Once the Jetson is booted, run the following commands.

```bash
    $ sudo apt-get update
    $ sudo apt-get upgrade
```
It will take some time depending if this is the first time done after a new flash and also on your internet speed. When done, reboot. 

After the reboot completes, install the Ultralytics package using the regular command
```bash
    $ pip3 install ultralytics
        or
    $ pip install ultralytics
        or
    $ pip3 install ultralytics==8.0.225           #previous version (Ideal, Not too new or old)
```
#### Final Check
Open a terminal and type them
```bash
    $ python3                # check if python version is 3.8

    >>> import ultralytics   # check if it is correctly imported
```
It should be ok by now. Make sure to add a swap file. Now play around just as you could do on Windows. Just when you run a code, run it through the terminal. **Exp: python3 my_yolo_code.py**

