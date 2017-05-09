func strStr(haystack string, needle string) int {
	len_hay, len_ned := len(haystack), len(needle)
	if len_hay == 0 && 0 == len_ned {
		return 0
	}
	if len_hay < len_ned {
		return -1
	}
	start, shift := 0, 0
	for start < len_hay {
		for start+shift < len_hay && haystack[start+shift] == needle[shift] {
			shift++
			if shift == len_ned {
				return start
			}
		}

		shift = 0
		start++
	}

	return -1
}
