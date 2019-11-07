#ifndef VM_FRAME
#define VM_FRAME

#include <list.h>
#include "vm/page.h"
#include "threads/thread.h"
#include "threads/palloc.h"

struct frame_table_entry
{
  void *frame;
  struct thread *t;
  struct spt_entry *spte;
  struct list_elem elem;
};

static void add_to_frame_table (void *, struct spt_entry *);

void frame_table_init (void);
void *allocate_frame_to_page (enum palloc_flags, struct spt_entry *);

#endif
