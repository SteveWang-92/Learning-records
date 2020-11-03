#!/usr/bin/env python2
# -*- coding: utf-8 -*-
##################################################
# GNU Radio Python Flow Graph
# Title: Udp Tx
# Generated: Wed Oct 14 07:37:10 2020
##################################################


if __name__ == '__main__':
    import ctypes
    import sys
    if sys.platform.startswith('linux'):
        try:
            x11 = ctypes.cdll.LoadLibrary('libX11.so')
            x11.XInitThreads()
        except:
            print "Warning: failed to XInitThreads()"

from gnuradio import blocks
from gnuradio import digital
from gnuradio import eng_notation
from gnuradio import gr
from gnuradio import wxgui
from gnuradio.eng_option import eng_option
from gnuradio.filter import firdes
from gnuradio.wxgui import constsink_gl
from gnuradio.wxgui import forms
from grc_gnuradio import blks2 as grc_blks2
from grc_gnuradio import wxgui as grc_wxgui
from optparse import OptionParser
import osmosdr
import time
import wx


class udp_tx(grc_wxgui.top_block_gui):

    def __init__(self):
        grc_wxgui.top_block_gui.__init__(self, title="Udp Tx")
        _icon_path = "/usr/share/icons/hicolor/32x32/apps/gnuradio-grc.png"
        self.SetIcon(wx.Icon(_icon_path, wx.BITMAP_TYPE_ANY))

        ##################################################
        # Variables
        ##################################################
        self.samp_rate = samp_rate = 2e6
        self.RFGain_rx = RFGain_rx = 10
        self.IFGain_tx = IFGain_tx = 30
        self.IFGain_rx = IFGain_rx = 30
        self.CenterFreq_tx = CenterFreq_tx = 500e6
        self.CenterFreq_rx = CenterFreq_rx = 500e6
        self.BBGain_tx = BBGain_tx = 30
        self.BBGain_rx = BBGain_rx = 30

        ##################################################
        # Blocks
        ##################################################
        _IFGain_tx_sizer = wx.BoxSizer(wx.VERTICAL)
        self._IFGain_tx_text_box = forms.text_box(
        	parent=self.GetWin(),
        	sizer=_IFGain_tx_sizer,
        	value=self.IFGain_tx,
        	callback=self.set_IFGain_tx,
        	label='IFGain_tx',
        	converter=forms.float_converter(),
        	proportion=0,
        )
        self._IFGain_tx_slider = forms.slider(
        	parent=self.GetWin(),
        	sizer=_IFGain_tx_sizer,
        	value=self.IFGain_tx,
        	callback=self.set_IFGain_tx,
        	minimum=1,
        	maximum=40,
        	num_steps=100,
        	style=wx.SL_HORIZONTAL,
        	cast=float,
        	proportion=1,
        )
        self.Add(_IFGain_tx_sizer)
        _CenterFreq_tx_sizer = wx.BoxSizer(wx.VERTICAL)
        self._CenterFreq_tx_text_box = forms.text_box(
        	parent=self.GetWin(),
        	sizer=_CenterFreq_tx_sizer,
        	value=self.CenterFreq_tx,
        	callback=self.set_CenterFreq_tx,
        	label='CenterFreq_tx',
        	converter=forms.float_converter(),
        	proportion=0,
        )
        self._CenterFreq_tx_slider = forms.slider(
        	parent=self.GetWin(),
        	sizer=_CenterFreq_tx_sizer,
        	value=self.CenterFreq_tx,
        	callback=self.set_CenterFreq_tx,
        	minimum=450e6,
        	maximum=600e6,
        	num_steps=100,
        	style=wx.SL_HORIZONTAL,
        	cast=float,
        	proportion=1,
        )
        self.Add(_CenterFreq_tx_sizer)
        _BBGain_tx_sizer = wx.BoxSizer(wx.VERTICAL)
        self._BBGain_tx_text_box = forms.text_box(
        	parent=self.GetWin(),
        	sizer=_BBGain_tx_sizer,
        	value=self.BBGain_tx,
        	callback=self.set_BBGain_tx,
        	label='BBGain_tx',
        	converter=forms.float_converter(),
        	proportion=0,
        )
        self._BBGain_tx_slider = forms.slider(
        	parent=self.GetWin(),
        	sizer=_BBGain_tx_sizer,
        	value=self.BBGain_tx,
        	callback=self.set_BBGain_tx,
        	minimum=1,
        	maximum=40,
        	num_steps=100,
        	style=wx.SL_HORIZONTAL,
        	cast=float,
        	proportion=1,
        )
        self.Add(_BBGain_tx_sizer)
        self.wxgui_constellationsink2_0 = constsink_gl.const_sink_c(
        	self.GetWin(),
        	title='Constellation Plot',
        	sample_rate=samp_rate,
        	frame_rate=5,
        	const_size=2048,
        	M=4,
        	theta=0,
        	loop_bw=6.28/100.0,
        	fmax=0.06,
        	mu=0.5,
        	gain_mu=0.005,
        	symbol_rate=samp_rate/4.,
        	omega_limit=0.005,
        )
        self.Add(self.wxgui_constellationsink2_0.win)
        self.osmosdr_sink_0 = osmosdr.sink( args="numchan=" + str(1) + " " + 'hackrf=21650cc3' )
        self.osmosdr_sink_0.set_sample_rate(samp_rate)
        self.osmosdr_sink_0.set_center_freq(CenterFreq_tx, 0)
        self.osmosdr_sink_0.set_freq_corr(0, 0)
        self.osmosdr_sink_0.set_gain(0, 0)
        self.osmosdr_sink_0.set_if_gain(IFGain_tx, 0)
        self.osmosdr_sink_0.set_bb_gain(BBGain_tx, 0)
        self.osmosdr_sink_0.set_antenna('', 0)
        self.osmosdr_sink_0.set_bandwidth(0, 0)

        self.digital_gmsk_mod_0 = digital.gmsk_mod(
        	samples_per_symbol=2,
        	bt=0.35,
        	verbose=False,
        	log=False,
        )
        self.blocks_multiply_const_vxx_0 = blocks.multiply_const_vcc((1, ))
        self.blocks_file_source_0 = blocks.file_source(gr.sizeof_char*1, '/home/steve-wang/a.txt', True)
        self.blks2_packet_encoder_0 = grc_blks2.packet_mod_b(grc_blks2.packet_encoder(
        		samples_per_symbol=2,
        		bits_per_symbol=2,
        		preamble='',
        		access_code='',
        		pad_for_usrp=False,
        	),
        	payload_length=30,
        )
        _RFGain_rx_sizer = wx.BoxSizer(wx.VERTICAL)
        self._RFGain_rx_text_box = forms.text_box(
        	parent=self.GetWin(),
        	sizer=_RFGain_rx_sizer,
        	value=self.RFGain_rx,
        	callback=self.set_RFGain_rx,
        	label='RFGain_rx',
        	converter=forms.float_converter(),
        	proportion=0,
        )
        self._RFGain_rx_slider = forms.slider(
        	parent=self.GetWin(),
        	sizer=_RFGain_rx_sizer,
        	value=self.RFGain_rx,
        	callback=self.set_RFGain_rx,
        	minimum=1,
        	maximum=40,
        	num_steps=100,
        	style=wx.SL_HORIZONTAL,
        	cast=float,
        	proportion=1,
        )
        self.Add(_RFGain_rx_sizer)
        _IFGain_rx_sizer = wx.BoxSizer(wx.VERTICAL)
        self._IFGain_rx_text_box = forms.text_box(
        	parent=self.GetWin(),
        	sizer=_IFGain_rx_sizer,
        	value=self.IFGain_rx,
        	callback=self.set_IFGain_rx,
        	label='IFGain_rx',
        	converter=forms.float_converter(),
        	proportion=0,
        )
        self._IFGain_rx_slider = forms.slider(
        	parent=self.GetWin(),
        	sizer=_IFGain_rx_sizer,
        	value=self.IFGain_rx,
        	callback=self.set_IFGain_rx,
        	minimum=1,
        	maximum=40,
        	num_steps=100,
        	style=wx.SL_HORIZONTAL,
        	cast=float,
        	proportion=1,
        )
        self.Add(_IFGain_rx_sizer)
        _CenterFreq_rx_sizer = wx.BoxSizer(wx.VERTICAL)
        self._CenterFreq_rx_text_box = forms.text_box(
        	parent=self.GetWin(),
        	sizer=_CenterFreq_rx_sizer,
        	value=self.CenterFreq_rx,
        	callback=self.set_CenterFreq_rx,
        	label='CenterFreq_rx',
        	converter=forms.float_converter(),
        	proportion=0,
        )
        self._CenterFreq_rx_slider = forms.slider(
        	parent=self.GetWin(),
        	sizer=_CenterFreq_rx_sizer,
        	value=self.CenterFreq_rx,
        	callback=self.set_CenterFreq_rx,
        	minimum=450e6,
        	maximum=600e6,
        	num_steps=100,
        	style=wx.SL_HORIZONTAL,
        	cast=float,
        	proportion=1,
        )
        self.Add(_CenterFreq_rx_sizer)
        _BBGain_rx_sizer = wx.BoxSizer(wx.VERTICAL)
        self._BBGain_rx_text_box = forms.text_box(
        	parent=self.GetWin(),
        	sizer=_BBGain_rx_sizer,
        	value=self.BBGain_rx,
        	callback=self.set_BBGain_rx,
        	label='BBGain_rx',
        	converter=forms.float_converter(),
        	proportion=0,
        )
        self._BBGain_rx_slider = forms.slider(
        	parent=self.GetWin(),
        	sizer=_BBGain_rx_sizer,
        	value=self.BBGain_rx,
        	callback=self.set_BBGain_rx,
        	minimum=1,
        	maximum=40,
        	num_steps=100,
        	style=wx.SL_HORIZONTAL,
        	cast=float,
        	proportion=1,
        )
        self.Add(_BBGain_rx_sizer)

        ##################################################
        # Connections
        ##################################################
        self.connect((self.blks2_packet_encoder_0, 0), (self.digital_gmsk_mod_0, 0))
        self.connect((self.blocks_file_source_0, 0), (self.blks2_packet_encoder_0, 0))
        self.connect((self.blocks_multiply_const_vxx_0, 0), (self.osmosdr_sink_0, 0))
        self.connect((self.blocks_multiply_const_vxx_0, 0), (self.wxgui_constellationsink2_0, 0))
        self.connect((self.digital_gmsk_mod_0, 0), (self.blocks_multiply_const_vxx_0, 0))

    def get_samp_rate(self):
        return self.samp_rate

    def set_samp_rate(self, samp_rate):
        self.samp_rate = samp_rate
        self.wxgui_constellationsink2_0.set_sample_rate(self.samp_rate)
        self.osmosdr_sink_0.set_sample_rate(self.samp_rate)

    def get_RFGain_rx(self):
        return self.RFGain_rx

    def set_RFGain_rx(self, RFGain_rx):
        self.RFGain_rx = RFGain_rx
        self._RFGain_rx_slider.set_value(self.RFGain_rx)
        self._RFGain_rx_text_box.set_value(self.RFGain_rx)

    def get_IFGain_tx(self):
        return self.IFGain_tx

    def set_IFGain_tx(self, IFGain_tx):
        self.IFGain_tx = IFGain_tx
        self._IFGain_tx_slider.set_value(self.IFGain_tx)
        self._IFGain_tx_text_box.set_value(self.IFGain_tx)
        self.osmosdr_sink_0.set_if_gain(self.IFGain_tx, 0)

    def get_IFGain_rx(self):
        return self.IFGain_rx

    def set_IFGain_rx(self, IFGain_rx):
        self.IFGain_rx = IFGain_rx
        self._IFGain_rx_slider.set_value(self.IFGain_rx)
        self._IFGain_rx_text_box.set_value(self.IFGain_rx)

    def get_CenterFreq_tx(self):
        return self.CenterFreq_tx

    def set_CenterFreq_tx(self, CenterFreq_tx):
        self.CenterFreq_tx = CenterFreq_tx
        self._CenterFreq_tx_slider.set_value(self.CenterFreq_tx)
        self._CenterFreq_tx_text_box.set_value(self.CenterFreq_tx)
        self.osmosdr_sink_0.set_center_freq(self.CenterFreq_tx, 0)

    def get_CenterFreq_rx(self):
        return self.CenterFreq_rx

    def set_CenterFreq_rx(self, CenterFreq_rx):
        self.CenterFreq_rx = CenterFreq_rx
        self._CenterFreq_rx_slider.set_value(self.CenterFreq_rx)
        self._CenterFreq_rx_text_box.set_value(self.CenterFreq_rx)

    def get_BBGain_tx(self):
        return self.BBGain_tx

    def set_BBGain_tx(self, BBGain_tx):
        self.BBGain_tx = BBGain_tx
        self._BBGain_tx_slider.set_value(self.BBGain_tx)
        self._BBGain_tx_text_box.set_value(self.BBGain_tx)
        self.osmosdr_sink_0.set_bb_gain(self.BBGain_tx, 0)

    def get_BBGain_rx(self):
        return self.BBGain_rx

    def set_BBGain_rx(self, BBGain_rx):
        self.BBGain_rx = BBGain_rx
        self._BBGain_rx_slider.set_value(self.BBGain_rx)
        self._BBGain_rx_text_box.set_value(self.BBGain_rx)


def main(top_block_cls=udp_tx, options=None):

    tb = top_block_cls()
    tb.Start(True)
    tb.Wait()


if __name__ == '__main__':
    main()
