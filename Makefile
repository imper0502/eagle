KEYBOARD := eagle

ifndef $(KEYMAP)
KEYMAP := standard
endif

.PHONY: all init clean

$(KEYBOARD)_$(KEYMAP).hex: init
	docker run \
		--rm \
		--volume qmk_build:/qmk_firmware/.build \
		--mount=type=bind,source='$(shell pwd)',target=/qmk_firmware/keyboards/$(KEYBOARD) \
		qmk:env \
		/bin/bash -c \
		" \
			qmk compile --keyboard=$(KEYBOARD) --keymap=$(KEYMAP); \
			mv /qmk_firmware/$@ /qmk_firmware/keyboards/eagle/targets/$@ \
		"

init:
ifeq ($(shell `docker images -q qmk:env` 2> /dev/null),)
	docker build -t qmk:env resources
endif
	mkdir -p targets

clean:
	docker image rm qmk:env
	rm -rf targets
