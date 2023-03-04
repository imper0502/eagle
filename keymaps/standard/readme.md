# The standard keymap for eagle
```bash
docker run -it --rm -v qmk_build:/qmk_firmware/.build -v $(pwd):/qmk_firmware/keyboards/eagle -v $(pwd)/targets:/targets qmk:env /bin/bash

qmk compile -kb eagle -km standard

mv ./eagle_standard.hex ./keyboards/eagle/targets/eagle_standard_date.hex
```
