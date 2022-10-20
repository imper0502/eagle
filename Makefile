mkfile_path := $(abspath $(lastword $(MAKEFILE_LIST)))
current_dir := $(notdir $(patsubst %/,%,$(dir $(mkfile_path))))

ifndef $(keymap)
keymap := standard
endif

.PHONY: all init clean

$(current_dir)_$(keymap).hex: init
	docker run \
		--rm \
		--volume qmk_build:/qmk_firmware/.build \
		--mount=type=bind,source='$(shell pwd)',target=/qmk_firmware/keyboards/$(current_dir) \
		qmk:env \
		/bin/bash -c \
		" \
			qmk compile --keyboard=$(current_dir) --keymap=$(keymap); \
			mv /qmk_firmware/$@ /qmk_firmware/keyboards/$(current_dir)/targets/$@ \
		"

init:
ifeq ($(shell `docker images -q qmk:env` 2> /dev/null),)
	docker build -t qmk:env resources
endif
	mkdir -p targets

clean:
	docker image rm qmk:env
	rm -rf targets
