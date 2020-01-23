--Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
----------------------------------------------------------------------------------
--Tool Version: Vivado v.2019.2 (lin64) Build 2700185 Thu Oct 24 18:45:48 MDT 2019
--Date        : Thu Jan  2 14:56:26 2020
--Host        : poseidon running 64-bit Debian GNU/Linux 10 (buster)
--Command     : generate_target camera_wrapper.bd
--Design      : camera_wrapper
--Purpose     : IP block netlist
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
library UNISIM;
use UNISIM.VCOMPONENTS.ALL;
entity camera_wrapper is
  port (
    CAMERA_tri_io : inout STD_LOGIC_VECTOR ( 10 downto 0 );
    DDR_addr : inout STD_LOGIC_VECTOR ( 14 downto 0 );
    DDR_ba : inout STD_LOGIC_VECTOR ( 2 downto 0 );
    DDR_cas_n : inout STD_LOGIC;
    DDR_ck_n : inout STD_LOGIC;
    DDR_ck_p : inout STD_LOGIC;
    DDR_cke : inout STD_LOGIC;
    DDR_cs_n : inout STD_LOGIC;
    DDR_dm : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    DDR_dq : inout STD_LOGIC_VECTOR ( 31 downto 0 );
    DDR_dqs_n : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    DDR_dqs_p : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    DDR_odt : inout STD_LOGIC;
    DDR_ras_n : inout STD_LOGIC;
    DDR_reset_n : inout STD_LOGIC;
    DDR_we_n : inout STD_LOGIC;
    FIXED_IO_ddr_vrn : inout STD_LOGIC;
    FIXED_IO_ddr_vrp : inout STD_LOGIC;
    FIXED_IO_mio : inout STD_LOGIC_VECTOR ( 53 downto 0 );
    FIXED_IO_ps_clk : inout STD_LOGIC;
    FIXED_IO_ps_porb : inout STD_LOGIC;
    FIXED_IO_ps_srstb : inout STD_LOGIC;
    SCCB_scl_io : inout STD_LOGIC;
    SCCB_sda_io : inout STD_LOGIC;
    XCLK : out STD_LOGIC
  );
end camera_wrapper;

architecture STRUCTURE of camera_wrapper is
  component camera is
  port (
    XCLK : out STD_LOGIC;
    CAMERA_tri_i : in STD_LOGIC_VECTOR ( 10 downto 0 );
    CAMERA_tri_o : out STD_LOGIC_VECTOR ( 10 downto 0 );
    CAMERA_tri_t : out STD_LOGIC_VECTOR ( 10 downto 0 );
    DDR_cas_n : inout STD_LOGIC;
    DDR_cke : inout STD_LOGIC;
    DDR_ck_n : inout STD_LOGIC;
    DDR_ck_p : inout STD_LOGIC;
    DDR_cs_n : inout STD_LOGIC;
    DDR_reset_n : inout STD_LOGIC;
    DDR_odt : inout STD_LOGIC;
    DDR_ras_n : inout STD_LOGIC;
    DDR_we_n : inout STD_LOGIC;
    DDR_ba : inout STD_LOGIC_VECTOR ( 2 downto 0 );
    DDR_addr : inout STD_LOGIC_VECTOR ( 14 downto 0 );
    DDR_dm : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    DDR_dq : inout STD_LOGIC_VECTOR ( 31 downto 0 );
    DDR_dqs_n : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    DDR_dqs_p : inout STD_LOGIC_VECTOR ( 3 downto 0 );
    FIXED_IO_mio : inout STD_LOGIC_VECTOR ( 53 downto 0 );
    FIXED_IO_ddr_vrn : inout STD_LOGIC;
    FIXED_IO_ddr_vrp : inout STD_LOGIC;
    FIXED_IO_ps_srstb : inout STD_LOGIC;
    FIXED_IO_ps_clk : inout STD_LOGIC;
    FIXED_IO_ps_porb : inout STD_LOGIC;
    SCCB_scl_i : in STD_LOGIC;
    SCCB_scl_o : out STD_LOGIC;
    SCCB_scl_t : out STD_LOGIC;
    SCCB_sda_i : in STD_LOGIC;
    SCCB_sda_o : out STD_LOGIC;
    SCCB_sda_t : out STD_LOGIC
  );
  end component camera;
  component IOBUF is
  port (
    I : in STD_LOGIC;
    O : out STD_LOGIC;
    T : in STD_LOGIC;
    IO : inout STD_LOGIC
  );
  end component IOBUF;
  signal CAMERA_tri_i_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal CAMERA_tri_i_1 : STD_LOGIC_VECTOR ( 1 to 1 );
  signal CAMERA_tri_i_10 : STD_LOGIC_VECTOR ( 10 to 10 );
  signal CAMERA_tri_i_2 : STD_LOGIC_VECTOR ( 2 to 2 );
  signal CAMERA_tri_i_3 : STD_LOGIC_VECTOR ( 3 to 3 );
  signal CAMERA_tri_i_4 : STD_LOGIC_VECTOR ( 4 to 4 );
  signal CAMERA_tri_i_5 : STD_LOGIC_VECTOR ( 5 to 5 );
  signal CAMERA_tri_i_6 : STD_LOGIC_VECTOR ( 6 to 6 );
  signal CAMERA_tri_i_7 : STD_LOGIC_VECTOR ( 7 to 7 );
  signal CAMERA_tri_i_8 : STD_LOGIC_VECTOR ( 8 to 8 );
  signal CAMERA_tri_i_9 : STD_LOGIC_VECTOR ( 9 to 9 );
  signal CAMERA_tri_io_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal CAMERA_tri_io_1 : STD_LOGIC_VECTOR ( 1 to 1 );
  signal CAMERA_tri_io_10 : STD_LOGIC_VECTOR ( 10 to 10 );
  signal CAMERA_tri_io_2 : STD_LOGIC_VECTOR ( 2 to 2 );
  signal CAMERA_tri_io_3 : STD_LOGIC_VECTOR ( 3 to 3 );
  signal CAMERA_tri_io_4 : STD_LOGIC_VECTOR ( 4 to 4 );
  signal CAMERA_tri_io_5 : STD_LOGIC_VECTOR ( 5 to 5 );
  signal CAMERA_tri_io_6 : STD_LOGIC_VECTOR ( 6 to 6 );
  signal CAMERA_tri_io_7 : STD_LOGIC_VECTOR ( 7 to 7 );
  signal CAMERA_tri_io_8 : STD_LOGIC_VECTOR ( 8 to 8 );
  signal CAMERA_tri_io_9 : STD_LOGIC_VECTOR ( 9 to 9 );
  signal CAMERA_tri_o_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal CAMERA_tri_o_1 : STD_LOGIC_VECTOR ( 1 to 1 );
  signal CAMERA_tri_o_10 : STD_LOGIC_VECTOR ( 10 to 10 );
  signal CAMERA_tri_o_2 : STD_LOGIC_VECTOR ( 2 to 2 );
  signal CAMERA_tri_o_3 : STD_LOGIC_VECTOR ( 3 to 3 );
  signal CAMERA_tri_o_4 : STD_LOGIC_VECTOR ( 4 to 4 );
  signal CAMERA_tri_o_5 : STD_LOGIC_VECTOR ( 5 to 5 );
  signal CAMERA_tri_o_6 : STD_LOGIC_VECTOR ( 6 to 6 );
  signal CAMERA_tri_o_7 : STD_LOGIC_VECTOR ( 7 to 7 );
  signal CAMERA_tri_o_8 : STD_LOGIC_VECTOR ( 8 to 8 );
  signal CAMERA_tri_o_9 : STD_LOGIC_VECTOR ( 9 to 9 );
  signal CAMERA_tri_t_0 : STD_LOGIC_VECTOR ( 0 to 0 );
  signal CAMERA_tri_t_1 : STD_LOGIC_VECTOR ( 1 to 1 );
  signal CAMERA_tri_t_10 : STD_LOGIC_VECTOR ( 10 to 10 );
  signal CAMERA_tri_t_2 : STD_LOGIC_VECTOR ( 2 to 2 );
  signal CAMERA_tri_t_3 : STD_LOGIC_VECTOR ( 3 to 3 );
  signal CAMERA_tri_t_4 : STD_LOGIC_VECTOR ( 4 to 4 );
  signal CAMERA_tri_t_5 : STD_LOGIC_VECTOR ( 5 to 5 );
  signal CAMERA_tri_t_6 : STD_LOGIC_VECTOR ( 6 to 6 );
  signal CAMERA_tri_t_7 : STD_LOGIC_VECTOR ( 7 to 7 );
  signal CAMERA_tri_t_8 : STD_LOGIC_VECTOR ( 8 to 8 );
  signal CAMERA_tri_t_9 : STD_LOGIC_VECTOR ( 9 to 9 );
  signal SCCB_scl_i : STD_LOGIC;
  signal SCCB_scl_o : STD_LOGIC;
  signal SCCB_scl_t : STD_LOGIC;
  signal SCCB_sda_i : STD_LOGIC;
  signal SCCB_sda_o : STD_LOGIC;
  signal SCCB_sda_t : STD_LOGIC;
begin
CAMERA_tri_iobuf_0: component IOBUF
     port map (
      I => CAMERA_tri_o_0(0),
      IO => CAMERA_tri_io(0),
      O => CAMERA_tri_i_0(0),
      T => CAMERA_tri_t_0(0)
    );
CAMERA_tri_iobuf_1: component IOBUF
     port map (
      I => CAMERA_tri_o_1(1),
      IO => CAMERA_tri_io(1),
      O => CAMERA_tri_i_1(1),
      T => CAMERA_tri_t_1(1)
    );
CAMERA_tri_iobuf_10: component IOBUF
     port map (
      I => CAMERA_tri_o_10(10),
      IO => CAMERA_tri_io(10),
      O => CAMERA_tri_i_10(10),
      T => CAMERA_tri_t_10(10)
    );
CAMERA_tri_iobuf_2: component IOBUF
     port map (
      I => CAMERA_tri_o_2(2),
      IO => CAMERA_tri_io(2),
      O => CAMERA_tri_i_2(2),
      T => CAMERA_tri_t_2(2)
    );
CAMERA_tri_iobuf_3: component IOBUF
     port map (
      I => CAMERA_tri_o_3(3),
      IO => CAMERA_tri_io(3),
      O => CAMERA_tri_i_3(3),
      T => CAMERA_tri_t_3(3)
    );
CAMERA_tri_iobuf_4: component IOBUF
     port map (
      I => CAMERA_tri_o_4(4),
      IO => CAMERA_tri_io(4),
      O => CAMERA_tri_i_4(4),
      T => CAMERA_tri_t_4(4)
    );
CAMERA_tri_iobuf_5: component IOBUF
     port map (
      I => CAMERA_tri_o_5(5),
      IO => CAMERA_tri_io(5),
      O => CAMERA_tri_i_5(5),
      T => CAMERA_tri_t_5(5)
    );
CAMERA_tri_iobuf_6: component IOBUF
     port map (
      I => CAMERA_tri_o_6(6),
      IO => CAMERA_tri_io(6),
      O => CAMERA_tri_i_6(6),
      T => CAMERA_tri_t_6(6)
    );
CAMERA_tri_iobuf_7: component IOBUF
     port map (
      I => CAMERA_tri_o_7(7),
      IO => CAMERA_tri_io(7),
      O => CAMERA_tri_i_7(7),
      T => CAMERA_tri_t_7(7)
    );
CAMERA_tri_iobuf_8: component IOBUF
     port map (
      I => CAMERA_tri_o_8(8),
      IO => CAMERA_tri_io(8),
      O => CAMERA_tri_i_8(8),
      T => CAMERA_tri_t_8(8)
    );
CAMERA_tri_iobuf_9: component IOBUF
     port map (
      I => CAMERA_tri_o_9(9),
      IO => CAMERA_tri_io(9),
      O => CAMERA_tri_i_9(9),
      T => CAMERA_tri_t_9(9)
    );
SCCB_scl_iobuf: component IOBUF
     port map (
      I => SCCB_scl_o,
      IO => SCCB_scl_io,
      O => SCCB_scl_i,
      T => SCCB_scl_t
    );
SCCB_sda_iobuf: component IOBUF
     port map (
      I => SCCB_sda_o,
      IO => SCCB_sda_io,
      O => SCCB_sda_i,
      T => SCCB_sda_t
    );
camera_i: component camera
     port map (
      CAMERA_tri_i(10) => CAMERA_tri_i_10(10),
      CAMERA_tri_i(9) => CAMERA_tri_i_9(9),
      CAMERA_tri_i(8) => CAMERA_tri_i_8(8),
      CAMERA_tri_i(7) => CAMERA_tri_i_7(7),
      CAMERA_tri_i(6) => CAMERA_tri_i_6(6),
      CAMERA_tri_i(5) => CAMERA_tri_i_5(5),
      CAMERA_tri_i(4) => CAMERA_tri_i_4(4),
      CAMERA_tri_i(3) => CAMERA_tri_i_3(3),
      CAMERA_tri_i(2) => CAMERA_tri_i_2(2),
      CAMERA_tri_i(1) => CAMERA_tri_i_1(1),
      CAMERA_tri_i(0) => CAMERA_tri_i_0(0),
      CAMERA_tri_o(10) => CAMERA_tri_o_10(10),
      CAMERA_tri_o(9) => CAMERA_tri_o_9(9),
      CAMERA_tri_o(8) => CAMERA_tri_o_8(8),
      CAMERA_tri_o(7) => CAMERA_tri_o_7(7),
      CAMERA_tri_o(6) => CAMERA_tri_o_6(6),
      CAMERA_tri_o(5) => CAMERA_tri_o_5(5),
      CAMERA_tri_o(4) => CAMERA_tri_o_4(4),
      CAMERA_tri_o(3) => CAMERA_tri_o_3(3),
      CAMERA_tri_o(2) => CAMERA_tri_o_2(2),
      CAMERA_tri_o(1) => CAMERA_tri_o_1(1),
      CAMERA_tri_o(0) => CAMERA_tri_o_0(0),
      CAMERA_tri_t(10) => CAMERA_tri_t_10(10),
      CAMERA_tri_t(9) => CAMERA_tri_t_9(9),
      CAMERA_tri_t(8) => CAMERA_tri_t_8(8),
      CAMERA_tri_t(7) => CAMERA_tri_t_7(7),
      CAMERA_tri_t(6) => CAMERA_tri_t_6(6),
      CAMERA_tri_t(5) => CAMERA_tri_t_5(5),
      CAMERA_tri_t(4) => CAMERA_tri_t_4(4),
      CAMERA_tri_t(3) => CAMERA_tri_t_3(3),
      CAMERA_tri_t(2) => CAMERA_tri_t_2(2),
      CAMERA_tri_t(1) => CAMERA_tri_t_1(1),
      CAMERA_tri_t(0) => CAMERA_tri_t_0(0),
      DDR_addr(14 downto 0) => DDR_addr(14 downto 0),
      DDR_ba(2 downto 0) => DDR_ba(2 downto 0),
      DDR_cas_n => DDR_cas_n,
      DDR_ck_n => DDR_ck_n,
      DDR_ck_p => DDR_ck_p,
      DDR_cke => DDR_cke,
      DDR_cs_n => DDR_cs_n,
      DDR_dm(3 downto 0) => DDR_dm(3 downto 0),
      DDR_dq(31 downto 0) => DDR_dq(31 downto 0),
      DDR_dqs_n(3 downto 0) => DDR_dqs_n(3 downto 0),
      DDR_dqs_p(3 downto 0) => DDR_dqs_p(3 downto 0),
      DDR_odt => DDR_odt,
      DDR_ras_n => DDR_ras_n,
      DDR_reset_n => DDR_reset_n,
      DDR_we_n => DDR_we_n,
      FIXED_IO_ddr_vrn => FIXED_IO_ddr_vrn,
      FIXED_IO_ddr_vrp => FIXED_IO_ddr_vrp,
      FIXED_IO_mio(53 downto 0) => FIXED_IO_mio(53 downto 0),
      FIXED_IO_ps_clk => FIXED_IO_ps_clk,
      FIXED_IO_ps_porb => FIXED_IO_ps_porb,
      FIXED_IO_ps_srstb => FIXED_IO_ps_srstb,
      SCCB_scl_i => SCCB_scl_i,
      SCCB_scl_o => SCCB_scl_o,
      SCCB_scl_t => SCCB_scl_t,
      SCCB_sda_i => SCCB_sda_i,
      SCCB_sda_o => SCCB_sda_o,
      SCCB_sda_t => SCCB_sda_t,
      XCLK => XCLK
    );
end STRUCTURE;
