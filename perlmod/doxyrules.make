DOXY_EXEC_PATH = E:/IME/3 ano/Programação/Projeto 2018/Shilton_circuito_RLC
DOXYFILE = E:/IME/3 ano/Programação/Projeto 2018/Shilton_circuito_RLC/-
DOXYDOCS_PM = E:/IME/3 ano/Programação/Projeto 2018/Shilton_circuito_RLC/perlmod/DoxyDocs.pm
DOXYSTRUCTURE_PM = E:/IME/3 ano/Programação/Projeto 2018/Shilton_circuito_RLC/perlmod/DoxyStructure.pm
DOXYRULES = E:/IME/3 ano/Programação/Projeto 2018/Shilton_circuito_RLC/perlmod/doxyrules.make

.PHONY: clean-perlmod
clean-perlmod::
	rm -f $(DOXYSTRUCTURE_PM) \
	$(DOXYDOCS_PM)

$(DOXYRULES) \
$(DOXYMAKEFILE) \
$(DOXYSTRUCTURE_PM) \
$(DOXYDOCS_PM): \
	$(DOXYFILE)
	cd $(DOXY_EXEC_PATH) ; doxygen "$<"
