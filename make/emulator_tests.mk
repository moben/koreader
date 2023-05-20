TESTSUITES := all base front

COVERAGE_ARGS = --coverage --exclude-tags=nocov
COVERAGE_REPORT = $(INSTALL_DIR)/koreader/luacov.report.out

RUNTESTS = $(INSTALL_DIR)/koreader/runtests

test: test-all

$(TESTSUITES:%=test-%): all
	$(RUNTESTS) $(@:test-%=%) $(TARGS)

$(TESTSUITES:%=testcov-%): all
	$(RUNTESTS) $(@:testcov-%=%) $(COVERAGE_ARGS) $(TARGS)

cov: testcov-front
	sed -n -e '/^Summary$$/{h;n;p;H;g;:_loop;p;n;b_loop}' $(COVERAGE_REPORT)

cov-full: testcov-front
	cat $(COVERAGE_REPORT)

.PHONY: cov cov-full test $(TESTSUITES:%=testcov-%) $(TESTSUITES:%=test-%)
