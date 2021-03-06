/* $Id$
 *
 * OpenMAMA: The open middleware agnostic messaging API
 * Copyright (C) 2011 NYSE Technologies, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

#ifndef MamdaOrderImbalanceHandlerH
#define MamdaOrderImbalanceHandlerH

#include <mamda/MamdaConfig.h>

namespace Wombat
{

    class MamdaSubscription;
    class MamdaOrderImbalanceListener;
    class MamaMsg;
    class MamdaOrderImbalanceRecap;
    class MamdaOrderImbalanceUpdate;
    /**
     * MamdaOrderImbalanceHandler is an interface for applications that want to
     * have an easy way to handle order imbalance updates.  The interface defines
     * callback methods for different types of order-imbalance events:
     */
    class MAMDAExpDLL MamdaOrderImbalanceHandler
    {
    public:
        /**
         * Method invoked when a order imbalance is reported.
         *
         * @param subscription    The subscription which received this update.
         * @param listener        The listener which invoked this callback.
         * @param msg             The MamaMsg that triggered this invocation.
         * @param imbalance       Provides access to imbalance details
         * @param update          Provides access to update details
       */
        virtual void onOrderImbalance (
            MamdaSubscription*           subscription,
            MamdaOrderImbalanceListener& listener,
            const MamaMsg&               msg,
            MamdaOrderImbalanceRecap&    imbalance,
            MamdaOrderImbalanceUpdate&   update) = 0;
        /**
         * Method invoked when a no order imbalance is reported.
         *
         * @param subscription    The subscription which received this update.
         * @param listener        The listener which invoked this callback.
         * @param msg             The MamaMsg that triggered this invocation.
         * @param imbalance       Provides access to imbalance details
         * @param update          Provides access to update details
       */
        virtual void onNoOrderImbalance (
            MamdaSubscription*           subscription,
            MamdaOrderImbalanceListener& listener,
            const MamaMsg&               msg,
            MamdaOrderImbalanceRecap&    imbalance,
            MamdaOrderImbalanceUpdate&   update) = 0;

        /**
         * Method invoked when the current order imbalance information
         * is available.  The reason for the invocation may be
         * any of the following:
         * - Initial image.
         * - Recap update (e.g., after server fault tolerant event or data
         *   quality event.)
         * - After stale status removed.
         * @param subscription The subscription which received this update
         * @param listener     The listener which invoked this callback
         * @param msg          The MamaMsg that triggered this invocation
         * @param imbalance    Provides access to imbalance details
         */
        virtual void onOrderImbalanceRecap (
            MamdaSubscription*           subscription,
            MamdaOrderImbalanceListener& listener,
            const MamaMsg&               msg,
            MamdaOrderImbalanceRecap&    imbalance) = 0;

        virtual ~MamdaOrderImbalanceHandler() {};
    };

}//namespace
#endif
