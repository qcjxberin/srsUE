/**
 *
 * \section COPYRIGHT
 *
 * Copyright 2015 The srsUE Developers. See the
 * COPYRIGHT file at the top-level directory of this distribution.
 *
 * \section LICENSE
 *
 * This file is part of the srsUE library.
 *
 * srsUE is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * srsUE is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * A copy of the GNU Affero General Public License can be found in
 * the LICENSE file in the top-level directory of this distribution
 * and at http://www.gnu.org/licenses/.
 *
 */

#ifndef PDCP_H
#define PDCP_H

#include "common/log.h"
#include "common/common.h"
#include "common/interfaces.h"
#include "upper/pdcp_entity.h"

namespace srsue {

class pdcp
    :public pdcp_interface_gw
    ,public pdcp_interface_rlc
    ,public pdcp_interface_rrc
{
public:
  pdcp();
  void init(rlc_interface_pdcp *rlc_, rrc_interface_pdcp *rrc_, gw_interface_pdcp *gw_, srslte::log *pdcp_log_);
  void stop();

  void write_sdu(uint32_t lcid, srsue_byte_buffer_t *sdu);

  void write_pdu(uint32_t lcid, srsue_byte_buffer_t *sdu);
  void write_pdu_bcch_bch(srsue_byte_buffer_t *sdu);
  void write_pdu_bcch_dlsch(srsue_byte_buffer_t *sdu);

private:
  srslte::log        *pdcp_log;
  pdcp_entity         pdcp_array[SRSUE_N_RADIO_BEARERS];
  rlc_interface_pdcp *rlc;
  rrc_interface_pdcp *rrc;
  gw_interface_pdcp  *gw;

  bool valid_lcid(uint32_t lcid);
};

} // namespace srsue


#endif // PDCP_H
