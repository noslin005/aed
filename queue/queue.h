//
//  queue.h
//  queue
//
//  Created by Nilson Lopes on 29/06/14.
//  Copyright (c) 2014 Nilson Lopes. All rights reserved.
//

#ifndef _libqueue_h
#define _libqueue_h

struct q_node{
    int data;
    struct q_node *next;
};

extern struct q_node *first;
extern struct q_node *last;

struct q_node* q_new_node(int data);
void q_init(void);
void q_insert(int data);
void q_delete(void);
void q_show(void);

int is_on_queue(int data);
void pause(void);
#endif
