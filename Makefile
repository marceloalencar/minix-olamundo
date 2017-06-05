# Makefile for the hello driver.
PROG=	olamundo
SRCS=	olamundo.c

FILES=	$(PROG).conf
FILESNAME=	$(PROG)
FILESDIR=	/etc/system.conf.d

.include <minix.service.mk>
