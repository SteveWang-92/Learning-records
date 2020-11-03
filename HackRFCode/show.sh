#!/bin/bash
# Author: Steve Wang
# Created Time: 2020年10月14日 星期三 07时23分22秒
python2.7 udp_tx/udp_tx.py &
sleep 2
python2.7 limegmsk/top_block.py &
sleep 2
python2.7 udp_rx/udp_rx.py &
