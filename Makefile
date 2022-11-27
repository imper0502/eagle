MAKEFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
CURRENT_DIR := $(notdir $(patsubst %/,%,$(dir $(MAKEFILE_PATH))))

ifndef $(KEYMAP)
KEYMAP := standard
endif

.PHONY: all init clean

$(CURRENT_DIR)_$(KEYMAP).hex: init
	docker run \
		--rm \
		-v qmk_build:/qmk_firmware/.build \
		-v $$(pwd):/qmk_firmware/keyboards/$(CURRENT_DIR) \
		-v $$(pwd)/targets:/targets \
		qmk:env \
		/bin/bash -c " \
			qmk compile -kb=$(CURRENT_DIR) -km=$(KEYMAP); \
			mv /qmk_firmware/$@ /targets/$@ \
		"

init:
	mkdir -p targets
ifeq ($(shell `docker images -q qmk:env` 2> /dev/null),)
	docker build -t qmk:env .
endif

clean:
	docker image rm qmk:env
	rm -rf targets
