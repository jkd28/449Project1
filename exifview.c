#include <stdio.h>
int main(int argc, char *argv[]){
	/*define struct for te first 20 bytes of image */
	struct first_tag {
		char start_marker[2];
		char APP1_marker[2];
		char APP1[2];
		char exif_string[4];
		char nul_zero[2];
		char endian[2];
		char version_num[2];
		char offset[4];
		unsigned short count;
	};
	
	struct TIFF_tag {
		char ident[2];
		char type[2];
		char num_items[4];
		char val_offset[4];
	};
	struct first_tag tag;
	struct TIFF_tag tiff_array[3];
	struct TIFF_tag temp_tiff;
	/*identifiers for TIFF tags that we care about*/
	int man_string = 0x010F;
	int cam_mod = 0x0110;
	int sub_block_address = 0x8769;
	int i;
	
	/* open file*/
	FILE *f = fopen(argv[1], "rb");
	if (f == NULL){
		printf("Input file does not exist.  Terminating program.\n\n");
		return 0;
	}
	
	 /*read first tag of .JPG file and get count */
	fread(&tag, sizeof(tag), 1, f);
	/*
	TEST LINES FOR READING INITIAL TAGS
	printf("First Marker: %#0X %#0X\n", tag.start_marker[0], tag.start_marker[1]);
	printf("APP1 Marker: %#0X %#0X\n", tag.APP1_marker[0], tag.APP1_marker[1]);
	printf("APP1 Block: %c %c\n", tag.APP1[0], tag.APP1[1]);
	printf("Exif String: %s\n", tag.exif_string);
	printf("Endianness: %s\n", tag.endian);
	printf("Number of TIFF Tags: %hd\n", tag.count);
	*/
	
	/*loop through and get TIFF tags we care about*/
	for(i = 0; i < tag.count; i++){
		fread(&temp_tiff, sizeof(temp_tiff), 1, f);
		/*if tag identifier matches any we care about, save this tag to tiff_array*/
		printf("Identity of TIFF: %#2x%#2x\n", temp_tiff.ident[1], temp_tiff.ident[0]);
	}
	
	return 0;
}
