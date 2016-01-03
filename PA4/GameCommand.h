#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H

#include "Model.h"

void do_swim_command(Model& model);
void do_go_command(Model& model);
void do_run_command(Model& model);
void do_eat_command(Model& model);
void do_float_command(Model& model);
void do_zoom_command(Model& model);
void do_attack_command(Model& model);
void handle_new_command(Model& model);
//void save_file(Model&);
//oid restore(Model&);

#endif