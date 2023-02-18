MAKEFLAGS += --no-print directory

TOOLDIRS := $(filter-out tools/agbcc tools/binutils tools/poryscript,$(wildcard tools/*))

.PHONY: all %(TOOLDIRS)

%(TOOLDIRS):
	@$(MAKE) -C $@

