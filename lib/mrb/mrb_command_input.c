/* -*- c-basic-offset: 2 -*- */
/*
  Copyright(C) 2015 Brazil

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License version 2.1 as published by the Free Software Foundation.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "../grn_ctx_impl.h"
#include <groonga/command.h>

#ifdef GRN_WITH_MRUBY
#include <mruby.h>
#include <mruby/class.h>
#include <mruby/data.h>
#include <mruby/value.h>
#include <mruby/string.h>

#include "mrb_ctx.h"
#include "mrb_command_input.h"

static struct mrb_data_type mrb_grn_command_input_type = {
  "Groonga::CommandInput",
  NULL
};

static mrb_value
mrb_grn_command_input_initialize(mrb_state *mrb, mrb_value self)
{
  mrb_value mrb_command_input_ptr;

  mrb_get_args(mrb, "o", &mrb_command_input_ptr);
  DATA_TYPE(self) = &mrb_grn_command_input_type;
  DATA_PTR(self) = mrb_cptr(mrb_command_input_ptr);
  return self;
}

void
grn_mrb_command_input_init(grn_ctx *ctx)
{
  grn_mrb_data *data = &(ctx->impl->mrb);
  mrb_state *mrb = data->state;
  struct RClass *module = data->module;
  struct RClass *klass;

  klass = mrb_define_class_under(mrb, module, "CommandInput", mrb->object_class);
  MRB_SET_INSTANCE_TT(klass, MRB_TT_DATA);

  mrb_define_method(mrb, klass, "initialize",
                    mrb_grn_command_input_initialize, MRB_ARGS_REQ(1));
}
#endif