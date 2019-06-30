**AnalogsEnhancer v.1.0 by Rinnegatamante**
(ur0 mod by Yoti)

This little kernel plugin allows users to improve their experience with PSVITA analogs. It allows to:

- Set a specific deadzone value between 0 and 128 for each analog
- Enable software rescaling of analogs output for better precision (Thanks to rsn8887)
- Force PSVITA system to use ANALOG_WIDE mode even when ANALOG mode is used causing a better precision in general

**How to use:**

- Install the plugin under `*KERNEL` in your taiHen config file.
- Edit the `AnaEnCfg.txt` file according to what you need.
- Place the `AnaEnCfg.txt` file in `ur0:tai`.

**AnaEnCfg.txt structure:**

AnaEnCfg.txt has 4 values that can be edited:

Example of AnaEnCfg.txt:

`left=0,n;right=0,n`

First 0 value is the deadzone for left analog.

Second parameter for left is either if you want to enable or disable software rescaling (can be y or n which stands for yes and no).
The same applies for right analog.

**Credits:**
- rsn8887 for the radial scaling algorithm used for software rescaling.**
- All my Patroners for their awesome support:**
* 2Mourty
* Andyways
* CountDuckula
* Daniel Crane
* Defkyle
* Elwood Blues
* Florian Gaul
* Gelson Silva
* Jared Breland
* Justin
* Lars Zondervan
* gnmmarechal
* Pirloui
* polytoad
* PSX-Place.com
* Ramerson Wesley Araújo
* Roman Murashow
* rsn8887
* Samuel Batista
* T33Hud
* Troy Murray
* Yakara Network