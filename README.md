# ibm-f

Non-destructive XT to BLE HID bridge for the [IBM Model F (`'XT'`, 1981)](https://en.wikipedia.org/wiki/Model_F_keyboard).

Built using a [TinyPICO](https://www.tinypico.com/) with [PlatformIO](https://platformio.org/).

The original 1981 IBM Model F, shipped primarily for the IBM Personal Computer, used the `XT` protocol. The signaling protocol was unique from its AT, PS2, and USB decendents, and old enough for me to struggle to find any useful information on it (outside of impossible-to-read C source code of random projects).

After a long time digging, I stumbled on this amazing website <<http://www.kbdbabel.org>>. It's the only one that seemed to outline the actual [signal line](http://www.kbdbabel.org/signaling/index.html) used by the board (which I verified with an oscilloscope).

This website <<https://sharktastica.co.uk/topics/kb_connections#HeaderPinouts>> provided the actual board-side pinouts, supplemented by [this diagram](https://sharktastica.co.uk/resources/images/pinouts/host_xt-at_180din5.jpg) from the same website.

## License

Copyright (c) 2022 Elias Gabriel under the [MIT License](./LICENSE).
