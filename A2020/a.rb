if File.exists?("input")
  $stdin = File.open("input")
  $stdout = File.open("output","w")
end

