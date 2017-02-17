ac_latex_class (LaTeX Support)

AC_INIT(newtonRaphson, 0.0 , bachar.bouazza@gmail.com)
AM_INIT_AUTOMAKE

AC_CHECK_PROG(PDFLATEX, pdflatex, pdflatex)
if test -z "$PDFLATEX"; then
  AC_MSG_WARN([Unable to create PDF version of the user manual.])
fi
AM_CONDITIONAL([HAVE_PDFLATEX], test -n "$PDFLATEX")
AC_PROG_CXX

AC_OUTPUT(Makefile src/Makefile tests/Makefile latex/Makefile)
