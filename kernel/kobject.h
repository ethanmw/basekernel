/*
 * Copyright (C) 2018 The University of Notre Dame This software is
 * distributed under the GNU General Public License. See the file LICENSE
 * for details. 
 */

#ifndef KOBJECT_H
#define KOBJECT_H

#include "fs.h"
#include "device.h"
#include "graphics.h"
#include "kernel/ktypes.h"
#include "pipe.h"

struct kobject {
	union {
		struct device *device;
		struct fs_file *file;
		struct graphics *graphics;
		struct pipe *pipe;
	} data;
	kobject_type type;
	int refcount;
	int offset;
	char *intent;
};

struct kobject *kobject_create_file(struct fs_file *f);
struct kobject *kobject_create_device(struct device *d);
struct kobject *kobject_create_graphics(struct graphics *g);
struct kobject *kobject_create_pipe(struct pipe *p);

struct kobject *kobject_addref(struct kobject *k);

int kobject_read(struct kobject *kobject, void *buffer, int size);
int kobject_read_nonblock(struct kobject *kobject, void *buffer, int size);
int kobject_write(struct kobject *kobject, void *buffer, int size);
int kobject_close(struct kobject *kobject);
int kobject_set_blocking(struct kobject *kobject, int b);
int kobject_get_dimensions(struct kobject *kobject, int *dimensions, int n);
int kobject_get_type(struct kobject *kobject);
int kobject_set_intent(struct kobject *kobject, char *new_intent);
int kobject_get_intent(struct kobject *kobject, char *buffer, int buffer_size);

#endif
