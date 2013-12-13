#DSPController


__DSPController__ is an embedded human interface device that connects to the _Analog Devices_ __SHARC ADSP-21364__ evaluation board via SPI to upgrade its flexibility. The __DSPController__ bundle contains the hardware itself and the software API which can be used in the VisualDSP++ environment with the supported DSP chips.



_This repository contains a project that uses the lates DSPController driver and  demonstartes the basic usage of the  DSPController API._

---

### How to use this project

There are three files you should care about:

- __INTERFACE.c__ - _implements the interface state machine_
- __GLUE.h__ - _connects INTERFACE.c to DSP.c_
- __DSP.c__ - _implements the signal processing algorithm_

The project contains a basic volume control application, that uses encoder 3 to adjust the volume of the signal that flows through the DSP.


