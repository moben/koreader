dsp_dec_sources = files(
  'alpha_processing.c',
  'alpha_processing_mips_dsp_r2.c',
  'alpha_processing_neon.c',
  'cpu.c',
  'dec.c',
  'dec_clip_tables.c',
  'dec_mips32.c',
  'dec_mips_dsp_r2.c',
  'dec_msa.c',
  'dec_neon.c',
  'filters.c',
  'filters_mips_dsp_r2.c',
  'filters_msa.c',
  'filters_neon.c',
  'lossless.c',
  'lossless_mips_dsp_r2.c',
  'lossless_msa.c',
  'lossless_neon.c',
  'rescaler.c',
  'rescaler_mips32.c',
  'rescaler_mips_dsp_r2.c',
  'rescaler_msa.c',
  'rescaler_neon.c',
  'upsampling.c',
  'upsampling_mips_dsp_r2.c',
  'upsampling_msa.c',
  'upsampling_neon.c',
  'yuv.c',
  'yuv_mips32.c',
  'yuv_mips_dsp_r2.c',
  'yuv_neon.c',
  )

dsp_enc_sources = files(
  'cost.c',
  'cost_mips32.c',
  'cost_mips_dsp_r2.c',
  'cost_neon.c',
  'enc.c',
  'enc_mips32.c',
  'enc_mips_dsp_r2.c',
  'enc_msa.c',
  'enc_neon.c',
  'lossless_enc.c',
  'lossless_enc_mips32.c',
  'lossless_enc_mips_dsp_r2.c',
  'lossless_enc_msa.c',
  'lossless_enc_neon.c',
  'ssim.c',
  )

if has_sse2

  dsp_dec_sources += files(
    'alpha_processing_sse2.c',
    'dec_sse2.c',
    'filters_sse2.c',
    'lossless_sse2.c',
    'rescaler_sse2.c',
    'upsampling_sse2.c',
    'yuv_sse2.c',
    )

  dsp_enc_sources += files(
    'cost_sse2.c',
    'enc_sse2.c',
    'lossless_enc_sse2.c',
    'ssim_sse2.c',
    )

endif

if has_sse41

  dsp_dec_sources += files(
    'alpha_processing_sse41.c',
    'dec_sse41.c',
    'lossless_sse41.c',
    'upsampling_sse41.c',
    'yuv_sse41.c',
    )

  dsp_enc_sources += files(
    'enc_sse41.c',
    'lossless_enc_sse41.c',
    )

endif
